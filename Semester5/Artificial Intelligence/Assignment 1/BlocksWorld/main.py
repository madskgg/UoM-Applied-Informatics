import os
import time
import sys
import copy
import re
from queue import Queue, LifoQueue, PriorityQueue

# Σταθερές για τους αλγόριθμους αναζήτησης
METHODS = {
    "breadth": Queue(),  # FIFO ουρά για BFS.
    "depth": LifoQueue(),  # LIFO ουρά για DFS.
    "best": PriorityQueue(),  # PriorityQueue για Best First.
    "astar": PriorityQueue(),  # PriorityQueue για A*.
}

# Κλάση για την υλοποίηση του δέντρου αναζήτησης.
class Tree(object):

    def __init__(self, state, parent, move, h, g, f): # Κατασκευαστής της κλάσης
        self.state = state # Τρέχουσα κατάσταση
        self.parent = parent # Πατέρας
        self.move = move # Κίνηση
        self.h = h # Ευρετική συνάρτηση
        self.g = g # Κόστος μέχρι τον τρέχον κόμβο
        self.f = f # Συνολικό κόστος
        self.children = [] # Παιδιά

    # Μέθοδος για την εύρεση των παιδιών του τρέχοντος κόμβου
    def find_children(self, method, goal):

        moves = self.find_possible_moves() 
        for state in moves:
            g = self.g + 1
            if method == "astar": 
                h = self.heuristic(state[0], goal) 
                f = h + g 
                self.children.append(Tree(state[0], self, state[1], h=h, g=g, f=f)) 
            elif method == "best":
                h = self.heuristic(state[0], goal)
                self.children.append(Tree(state[0], self, state[1], h=h, g=g, f=h))
            else:
                self.children.append(Tree(state[0], self, state[1], h=0, g=g, f=0))

    # Μέθοδος για την εύρεση των δυνατών κινήσεων
    def find_possible_moves(self):
        # Εύρεση των καθαρών μπλοκ
        clear_blocks = { 
            key: value for key, value in self.state.items() if value["CLEAR"]
        }

        moves = [] 
        for block, value in clear_blocks.items():
            # Εάν το μπλοκ είναι πάνω σε κάποιο άλλο μπλοκ
            if value["ON"] != -1:
                # Μετακίνηση ενός καθαρού μπλοκ που βρίσκεται πάνω σε άλλο μπλοκ στο τραπέζι
                on = value["ON"]
                temp = self.clear_on_table(block, on) 
                moves.append(temp)
                
                # Μετακίνηση ενός μπλοκ που βρίσκεται στο τραπέζι σε ένα με καθαρή την επάνω έδρα του μπλοκ
                for block2 in clear_blocks:
                    if block != block2:
                        # Μετακίνηση ενός καθαρού μπλοκ που βρίσκεται στο τραπέζι σε ένα με καθαρή την επάνω έδρα του μπλοκ
                        temp = self.clear_on_clear(block, block2)
                        moves.append(temp)

            # Εάν το μπλοκ είναι στο τραπέζι
            elif value["ONTABLE"]:
                # Μετακίνηση ενός καθαρού μπλοκ που βρίσκεται στο τραπέζι σε ένα με καθαρή την επάνω έδρα του μπλοκ
                for block2 in clear_blocks:
                    if block != block2:
                        temp = self.table_on_clear(block, block2)
                        moves.append(temp)

        del clear_blocks # Διαγραφή των καθαρών μπλοκ   
        return moves

    # Μέθοδος για την μετακίνηση ενός καθαρού μπλοκ που βρίσκεται στο τραπέζι σε ένα με καθαρή την επάνω έδρα του μπλοκ
    def clear_on_table(self, block, on):

        # Αντιγραφή της τρέχουσας κατάστασης
        copy_blocks = {key: self.state[key].copy() for key in self.state}

        # Μεταβολή της κατάστασης
        copy_blocks[block]["ONTABLE"] = True # Το μπλοκ βρίσκεται στο τραπέζι
        copy_blocks[block]["ON"] = -1 # Το μπλοκ δεν βρίσκεται πάνω σε κάποιο άλλο μπλοκ
        copy_blocks[on]["CLEAR"] = True # Το μπλοκ πάνω στο οποίο βρισκόταν το μπλοκ που μετακινήθηκε είναι με καθαρή την επάνω έδρα του
        copy_blocks[on]["UNDER"] = -1 # Το μπλοκ πάνω στο οποίο βρισκόταν το μπλοκ που μετακινήθηκε δεν έχει κάτω του κάποιο μπλοκ
        move = (block, on, "table") 

        return copy_blocks, move

    # Μέθοδος για την μετακίνηση ενός μπλοκ που βρίσκεται στο τραπέζι σε ένα με καθαρή την επάνω έδρα του μπλοκ
    def table_on_clear(self, block, block2):

        # Αντιγραφή της τρέχουσας κατάστασης
        copy_blocks = {key: self.state[key].copy() for key in self.state}

        copy_blocks[block]["ONTABLE"] = False # Το μπλοκ δεν βρίσκεται πλέον στο τραπέζι
        copy_blocks[block]["ON"] = block2 # Το μπλοκ βρίσκεται πάνω στο block2
        copy_blocks[block2]["UNDER"] = block # Το block2 έχει κάτω του το block
        copy_blocks[block2]["CLEAR"] = False # Το block2 δεν είναι πλέον με καθαρή την επάνω έδρα του
        move = (block, "table", block2)

        return copy_blocks, move

    # Μέθοδος για την μετακίνηση ενός καθαρού μπλοκ που βρίσκεται πάνω σε άλλο μπλοκ στο τραπέζι
    def clear_on_clear(self, block, block2):

        # Αντιγραφή της τρέχουσας κατάστασης
        copy_blocks = {key: self.state[key].copy() for key in self.state}

        below_block = copy_blocks[block]["ON"] # Το μπλοκ πάνω στο οποίο βρίσκεται το block

        copy_blocks[block]["ON"] = block2 # Το μπλοκ βρίσκεται πλέον πάνω στο block2
        copy_blocks[below_block]["CLEAR"] = True # Το μπλοκ πάνω στο οποίο βρισκόταν το block είναι με καθαρή την επάνω έδρα του
        copy_blocks[below_block]["UNDER"] = -1 # Το μπλοκ πάνω στο οποίο βρισκόταν το block δεν έχει κάτω του κάποιο μπλοκ
        copy_blocks[block2]["UNDER"] = block # Το block2 έχει κάτω του το block
        copy_blocks[block2]["CLEAR"] = False # Το block2 δεν είναι πλέον με καθαρή την επάνω έδρα του
        move = (block, below_block, block2)

        return copy_blocks, move

    # Ευρετική συνάρτηση
    def heuristic(self, state, goal):

        score = 0

        for block in state:
            if state[block] != goal[block]:  
                # Εάν το μπλοκ δεν είναι στο τραπέζι
                score += 1  

                # Εάν το μπλοκ δεν είναι στο σωστό μπλοκ
                if not state[block]["ONTABLE"]:
                    current_on = state[block]["ON"] # Το μπλοκ πάνω στο οποίο βρίσκεται το block
                    goal_on = goal[block]["ON"] # Το μπλοκ πάνω στο οποίο θα έπρεπε να βρίσκεται το block

                    if current_on != goal_on: # Εάν το μπλοκ πάνω στο οποίο βρίσκεται το block δεν είναι το σωστό
                        score += 1  # Προσθήκη στο σκορ

        return score

    # Έλεγχος αν η τρέχουσα κατάσταση είναι η λύση
    def is_goal(self, goal):
        return self.state == goal

    # Μέθοδος για την εύρεση των κινήσεων που πρέπει να γίνουν για να φτάσουμε στη λύση
    def get_moves_to_solution(self):

        temp = copy.copy(self)
        path = []
        while temp.parent is not None:
            if temp.move is not None:
                path.append(temp.move)
            temp = temp.parent

        return path

    # Μέθοδος για την σύγκριση των κόμβων
    def __lt__(self, other):
        return self.f < other.f

    # Μέθοδος για την σύγκριση των κόμβων
    def __eq__(self, other):
        if other is not None:
            return self.state == other.state

# Μέθοδος αναζήτησης
def search(queue, method, initial, goal):
    root = Tree(initial, None, None, 0, 0, 0)  # Δημιουργία ρίζας του δέντρου.
    queue.put((0, root) if method in ("astar", "best") else root)  # Εισαγωγή της ρίζας στην ουρά
    visited = set()  # Δημιουργία συνόλου
    start_time = time.time()  # Καταγραφή χρόνου έναρξης.

    while not queue.empty() and (time.time() - start_time <= 120):  
        current = queue.get()[1] if method in ("astar", "best") else queue.get()
        if current.is_goal(goal):  # Έλεγχος αν έχει βρεθεί λύση.
            return current # Επιστροφή του κόμβου που περιέχει τη λύση.
        if str(current.state) in visited:  # Έλεγχος αν ο κόμβος έχει επισκεφθεί, εάν ναι προχωράμε στον επόμενο.
            continue 

        visited.add(str(current.state))  # Προσθήκη του κόμβου στο σύνολο
        current.find_children(method, goal)  # Εύρεση παιδιών του κόμβου

        for child in current.children:
            queue.put((child.f, child) if method in ("astar", "best") else child)  # Εισαγωγή των παιδιών στην ουρά
    return None  # Επιστροφή None εάν δεν βρεθεί λύση


def main():

    print("Starting search...")
    start_time = time.time() # Καταγραφή χρόνου έναρξης
    method, input_file, output_file = parse_arguments() # Ανάλυση των ορισμάτων της γραμμής εντολών
    search_queue = METHODS[method] # Επιλογή της ουράς ανάλογα με τον αλγόριθμο αναζήτησης
    data = load_problem(input_file) # Φόρτωση του προβλήματος από το αρχείο εισόδου
    objects = get_objects_from_file(data) # Εύρεση των αντικειμένων του προβλήματος
    initial_state = get_initial_state(data) # Εύρεση της αρχικής κατάστασης
    goal_state = get_goal_state(data) # Εύρεση της τελικής κατάστασης

    # Αναζήτηση λύσης
    solution_node = search(
        search_queue,
        method,
        initialize_blocks(objects, initial_state),
        initialize_blocks(objects, goal_state),
    )

    # Χειρισμός της λύσης
    handle_solution(solution_node, start_time, input_file, output_file, method)

# Μέθοδος για την ανάλυση των ορισμάτων της γραμμής εντολών
def parse_arguments():

    # Έλεγχος των ορισμάτων
    if len(sys.argv) < 3 or len(sys.argv) > 4:
        print(f"USAGE: {sys.argv[0]} <Search Algorithm> <Problem file name> <Solution file name>")
        sys.exit()

    method = sys.argv[1] # Αλγόριθμος αναζήτησης
    input_file = sys.argv[2] # Αρχείο εισόδου
    output_file = sys.argv[3] if len(sys.argv) == 4 else None # Αρχείο εξόδου
    return method, input_file, output_file

# Μέθοδος για τον χειρισμό της λύσης
def handle_solution(solution_node, start_time, input_file, output_file, method):

    if solution_node:
        print_solution(solution_node, start_time)
        write_solution_to_file(solution_node, input_file, output_file, method)
    else:
        print_no_solution_found(start_time)

# Μέθοδος για την εκτύπωση της λύσης
def print_solution(solution_node, start_time):

    print("SOLUTION FOUND! Check the solution file for more details.")
    print(f"Number of moves: {solution_node.g}")
    print(f"Cost: {solution_node.f}")
    print("Took: ", time.time() - start_time)

# Μέθοδος για την εγγραφή της λύσης σε αρχείο
def write_solution_to_file(solution_node, input_file, output_file, method):

    solution_path = solution_node.get_moves_to_solution()

    if output_file is None:

        file_name = os.path.basename(input_file)
        output_file = f"./solutions/{method}-{file_name}"

    write_solution(output_file, solution_path)

# Μέθοδος για την εκτύπωση μηνύματος όταν δεν βρεθεί λύση
def print_no_solution_found(start_time):
    print("Took: ", time.time() - start_time)
    print("No solution found, after 2 minutes of searching.")
    sys.exit()

# Μέθοδος για την φόρτωση του προβλήματος από το αρχείο εισόδου
def load_problem(input):

    data = [] # Αρχικοποίηση λίστας

    with open(input, "r") as file: # Άνοιγμα του αρχείου
        raw_data = file.readlines() # Ανάγνωση των γραμμών του αρχείου
        for line in raw_data:
            data.append(line.strip("\n").replace(" ", "-")) # Προσθήκη των γραμμών στη λίστα μετατρέποντας τα κενά σε "-"
    return data

# Μέθοδος για την εξαγωγή της αρχικής κατάστασης από τα δεδομένα του αρχείου εισόδου
def get_initial_state(data):

    flag = False
    initial_state = []

    for line in data:
        if re.match(r"\A\(:INIT", line, re.I) or flag: # Έλεγχος αν η γραμμή περιέχει την αρχική κατάσταση ή αν έχει βρεθεί η αρχική κατάσταση
            flag = True
            if re.match(r"\A\(:goal", line, re.I): # Έλεγχος αν η γραμμή περιέχει την τελική κατάσταση και διακοπή της αναζήτησης
                break
            pattern = r"CLEAR-\w{1}\d?|ONTABLE-\w{1}\d?|ON-\w{1}\d?-\w{1}\d?" # Πρότυπο για την εξαγωγή των καταστάσεων
            initial_state.extend(re.findall(pattern, line)) # Εξαγωγή των καταστάσεων
    return initial_state

# Μέθοδος για την εξαγωγή της τελικής κατάστασης από τα δεδομένα του αρχείου εισόδου
def get_goal_state(data):

    flag = False
    goal_state = []
    for line in data:
        if re.match(r"\A\(:goal", line, re.I) or flag: # Έλεγχος αν η γραμμή περιέχει την τελική κατάσταση ή αν έχει βρεθεί η τελική κατάσταση
            flag = True
            pattern = r"CLEAR-\w{1}\d?|ONTABLE-\w{1}\d?|ON-\w{1}\d?-\w{1}\d?" 
            goal_state.extend(re.findall(pattern, line)) # Εξαγωγή των καταστάσεων
    return goal_state

# Μέθοδος για την εξαγωγή των αντικειμένων από τα δεδομένα του αρχείου εισόδου
def get_objects_from_file(data):

    flag = False
    objects = []

    for line in data:
        if re.match(r"\A\(:object", line, re.I) or flag: # Έλεγχος αν η γραμμή περιέχει τα αντικείμενα ή αν έχουν βρεθεί τα αντικείμενα
            flag = True
            if re.match(r"\A\(:INIT", line, re.I): # Έλεγχος αν η γραμμή περιέχει την αρχική κατάσταση και διακοπή της αναζήτησης
                break
            objects.extend(re.findall(r"\w{1}\d?", line)) # Εξαγωγή των αντικειμένων
    return objects[7:] # Επιστροφή των αντικειμένων

# Μέθοδος για την αρχικοποίηση των μπλοκ
def initialize_blocks(objects, state):

    # Δημιουργία λεξικού με τα μπλοκ
    blocks = {
        id: {"CLEAR": True, "ON": -1, "UNDER": -1, "ONTABLE": True} for id in objects
    }

    for state in state:
        if len(state.split("-")) < 3: # Έλεγχος αν η κατάσταση περιέχει 2 ή 3 στοιχεία
            pos, block = state.split("-") # Διαχωρισμός της κατάστασης με 2 στοιχεία
        else:
            pos, block, on = state.split("-") # Διαχωρισμός της κατάστασης με 3 στοιχεία
        if pos == "CLEAR": 
            blocks[block][pos] = True # Το μπλοκ είναι με καθαρή την επάνω έδρα του
        elif pos == "ONTABLE":
            blocks[block][pos] = True # Το μπλοκ βρίσκεται στο τραπέζι
        else:
            blocks[on]["UNDER"] = block # Το μπλοκ βρίσκεται πάνω στο block 
            blocks[block][pos] = on # Το μπλοκ βρίσκεται πάνω στο block
            blocks[block]["ONTABLE"] = False # Το μπλοκ δεν βρίσκεται στο τραπέζι
            if blocks[on]["CLEAR"]: # Έλεγχος αν το μπλοκ πάνω στο οποίο βρίσκεται το μπλοκ είναι με καθαρή την επάνω έδρα του
                blocks[on]["CLEAR"] = False # Το μπλοκ πάνω στο οποίο βρίσκεται το μπλοκ δεν είναι πλέον με καθαρή την επάνω έδρα του

    return blocks

# Μέθοδος για την εγγραφή της λύσης σε αρχείο
def write_solution(file, solution_path):

    solution_path.reverse() # Αντιστροφή της λίστας
    with open(file, "w") as file: 
        for i, move in enumerate(solution_path): # Εγγραφή των κινήσεων στο αρχείο
            file.write(f"Move {move}\n") # Εγγραφή της κίνησης

if __name__ == "__main__":
    main()
