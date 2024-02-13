import os
import re
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB, BernoulliNB
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import nltk
nltk.download('punkt')
nltk.download('stopwords')

# Συνάρτηση για την προεπεξεργασία του κειμένου
def preprocess_text(text):
    # Αφαίρεση ειδικών χαρακτήρων και ψηφίων
    text = re.sub(r'[^a-zA-Z\s]', '', text)
    # Tokenization
    tokens = word_tokenize(text)
    # Stopword filtering και stemming
    stop_words = set(stopwords.words('english'))
    ps = PorterStemmer()
    filtered_tokens = [ps.stem(word.lower()) for word in tokens if word.lower() not in stop_words]
    return ' '.join(filtered_tokens)

# Συνάρτηση για τη φόρτωση θετικών και αρνητικών κριτικών
def load_reviews_from_directory(directory, label):
    reviews = []
    for filename in os.listdir(directory):
        with open(os.path.join(directory, filename), 'r', encoding='utf-8') as file:
            review = file.read()
            reviews.append((review, label))
    return reviews

# Καθορισμός καταλόγων με τις θετικές και αρνητικές κριτικές
positive_directory = r'C:\Users\ericm\Desktop\txt_sentoken\pos'
negative_directory = r'C:\Users\ericm\Desktop\txt_sentoken\neg'

# Φόρτωση θετικών και αρνητικών κριτικών
positive_reviews = load_reviews_from_directory(positive_directory, 'positive')
negative_reviews = load_reviews_from_directory(negative_directory, 'negative')

# Σύνολο θετικών και αρνητικών κριτικών
all_reviews = positive_reviews + negative_reviews

# Προεπεξεργασία των κριτικών και labeling
preprocessed_reviews = [preprocess_text(review[0]) for review in all_reviews]
labels = [review[1] for review in all_reviews]

# Χωρισμός των δεδομένων σε σύνολα εκπαίδευσης και αποτίμησης	
X_train, X_test, y_train, y_test = train_test_split(preprocessed_reviews, labels, test_size=0.2, random_state=42)

# Διανυσματοποίηση των εγγράφων με χρήση του CountVectorizer
vectorizer = CountVectorizer()
X_train_vectorized = vectorizer.fit_transform(X_train)
X_test_vectorized = vectorizer.transform(X_test)

# Multinomial Naive Bayes Classifier
mnb_classifier = MultinomialNB()
mnb_classifier.fit(X_train_vectorized, y_train)
mnb_predictions = mnb_classifier.predict(X_test_vectorized)

# Bernoulli Naive Bayes Classifier
vectorizer_binary = CountVectorizer(binary=True)
X_train_binary = vectorizer_binary.fit_transform(X_train)
X_test_binary = vectorizer_binary.transform(X_test)

bnb_classifier = BernoulliNB()
bnb_classifier.fit(X_train_binary, y_train)
bnb_predictions = bnb_classifier.predict(X_test_binary)

# Υπολογισμός και εκτύπωση στην οθόνη
print("---Classification Results---")

mnb_accuracy = accuracy_score(y_test, mnb_predictions)
print(f"Multinomial Naive Bayes Accuracy: {mnb_accuracy:.2f}")

bnb_accuracy = accuracy_score(y_test, bnb_predictions)
print(f"Bernoulli Naive Bayes Accuracy: {bnb_accuracy:.2f}")
