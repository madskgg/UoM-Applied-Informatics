import pandas as pd
import numpy as np
from scipy.stats import pearsonr
from sklearn.metrics import mean_absolute_error, precision_score, recall_score, confusion_matrix
from sklearn.model_selection import train_test_split
from tqdm import tqdm
import warnings
from sklearn.metrics.pairwise import cosine_similarity
import matplotlib.pyplot as plt

# Suppress UserWarning globally
warnings.simplefilter("ignore", category=UserWarning)

class MovieRecommender:
    def __init__(self, ratings, similarity_metric="pearson"):
        # Αποθήκευση του πίνακα αξιολογήσεων
        self.ratings = ratings
        self.similarity_metric = similarity_metric
        # Υπολογισμός του πίνακα ομοιότητας
        self.similarity_matrix = self.calculate_similarity_matrix()

    def calculate_similarity_matrix(self):
        num_items = self.ratings.shape[1]
        similarity_matrix = np.zeros((num_items, num_items))
        
        if self.similarity_metric == "cosine":
            # Υπολογισμός ομοιότητας cosine μεταξύ των αντικειμένων
            similarity_matrix = cosine_similarity(self.ratings.T)
        else:  # Pearson similarity
            for i in range(num_items):
                for j in range(i, num_items):
                    if i != j:
                        item1_ratings = self.ratings[:, i]
                        item2_ratings = self.ratings[:, j]
                        common_users = np.logical_and(item1_ratings != 0, item2_ratings != 0)
                        
                        if np.sum(common_users) > 1:
                            if np.all(item1_ratings[common_users] == item1_ratings[common_users][0]) or np.all(item2_ratings[common_users] == item2_ratings[common_users][0]):
                                similarity = 0  # Αν μια από τις στήλες έχει σταθερές τιμές, η ομοιότητα ορίζεται ως 0
                            else:
                                similarity, _ = pearsonr(item1_ratings[common_users], item2_ratings[common_users])
                            similarity_matrix[i, j] = similarity
                            similarity_matrix[j, i] = similarity
        return similarity_matrix

    # Πρόβλεψη με βάση τον σταθμισμένο μέσο όρο των N πιο κοντινών γειτόνων
    def predict_weighted_average(self, user_ratings, item_index, N):
        similar_items = np.argsort(self.similarity_matrix[item_index])[-N:]
        valid_similar_items = similar_items[user_ratings[similar_items] != 0]
        
        if len(valid_similar_items) == 0:
            return 0
        
        numerator = np.sum(self.similarity_matrix[item_index, valid_similar_items] * user_ratings[valid_similar_items])
        denominator = np.sum(np.abs(self.similarity_matrix[item_index, valid_similar_items]))
        
        return 0 if denominator == 0 else np.nan_to_num(numerator / denominator)
    
    # Πρόβλεψη που δίνει μεγαλύτερο βάρος στα δημοφιλή αντικείμενα
    def predict_weighted_popular(self, user_ratings, item_index, N):
        similar_items = np.argsort(self.similarity_matrix[item_index])[-N:]
        valid_similar_items = similar_items[user_ratings[similar_items] != 0]
        if len(valid_similar_items) == 0:
            return 0
        popularity = np.sum(self.ratings[:, valid_similar_items] != 0, axis=0)
        if np.max(popularity) == 0:
            return 0
        weights = popularity / np.max(popularity)
        
        numerator = np.sum(self.similarity_matrix[item_index, valid_similar_items] * user_ratings[valid_similar_items] * weights)
        denominator = np.sum(np.abs(self.similarity_matrix[item_index, valid_similar_items]) * weights)
        
        return 0 if denominator == 0 else np.nan_to_num(numerator / denominator)

    # Πρόβλεψη που δίνει μεγαλύτερο βάρος στα λιγότερο δημοφιλή αντικείμενα
    def predict_weighted_unpopular(self, user_ratings, item_index, N):
        similar_items = np.argsort(self.similarity_matrix[item_index])[-N:]
        valid_similar_items = similar_items[user_ratings[similar_items] != 0]
        if len(valid_similar_items) == 0:
            return 0
        popularity = np.sum(self.ratings[:, valid_similar_items] != 0, axis=0)
        if np.max(popularity) == 0:
            return 0
        weights = 1 / (popularity + 1)
        
        numerator = np.sum(self.similarity_matrix[item_index, valid_similar_items] * user_ratings[valid_similar_items] * weights)
        denominator = np.sum(np.abs(self.similarity_matrix[item_index, valid_similar_items]) * weights)
        
        return 0 if denominator == 0 else np.nan_to_num(numerator / denominator)

    # Αξιολόγηση του συστήματος χρησιμοποιώντας MAE, Precision, Recall
    def evaluate(self, test_ratings, N, prediction_function):
        all_predictions = []
        all_ground_truth = []
        user_averages = np.mean(test_ratings, axis=1)

        for user_index in range(test_ratings.shape[0]):
            user_ratings = test_ratings[user_index]
            for item_index in range(test_ratings.shape[1]):
                if user_ratings[item_index] != 0:
                    prediction = prediction_function(user_ratings, item_index, N)
                    all_predictions.append(prediction)
                    all_ground_truth.append(user_ratings[item_index])
        
        all_predictions = np.nan_to_num(all_predictions)
        all_ground_truth = np.nan_to_num(all_ground_truth)
        
        mae = mean_absolute_error(all_ground_truth, all_predictions)
        threshold = np.array(all_ground_truth) >= user_averages[:, None]
        predicted_threshold = np.array(all_predictions) >= user_averages[:, None]
        
        precision = precision_score(threshold.flatten(), predicted_threshold.flatten(), average='macro')
        recall = recall_score(threshold.flatten(), predicted_threshold.flatten(), average='macro')
        
        return mae, precision, recall

# Φόρτωση και προεπεξεργασία δεδομένων
ratings_data = pd.read_csv('ratings-reduced.csv')
M, M_prime = 5, 5  # Change as needed
movie_counts = ratings_data['movieId'].value_counts()
user_counts = ratings_data['userId'].value_counts()
filtered_movies = movie_counts[movie_counts >= M].index
filtered_users = user_counts[user_counts >= M_prime].index
ratings_data = ratings_data[ratings_data['movieId'].isin(filtered_movies) & ratings_data['userId'].isin(filtered_users)]
ratings_matrix = ratings_data.pivot(index='userId', columns='movieId', values='rating').fillna(0).values

# Υπολογισμός των μετρικών για διάφορες τιμές των παραμέτρων
T_values = [80, 50, 70, 90]
N_values = [5, 10, 15, 20, 25]

for T in T_values:
    for N in N_values:
        train_ratings, test_ratings = train_test_split(ratings_matrix, test_size=(100-T)/100, random_state=None)
        
        for similarity in ["pearson", "cosine"]:
            recommender = MovieRecommender(train_ratings, similarity)
            for method in [recommender.predict_weighted_average, recommender.predict_weighted_popular, recommender.predict_weighted_unpopular]:
                mae, precision, recall = recommender.evaluate(test_ratings, N, method)
                print(f"T={T}%, N={N}, Similarity={similarity}, Method={method.__name__}")
                print(f"MAE: {mae}, Precision: {precision}, Recall: {recall}")
