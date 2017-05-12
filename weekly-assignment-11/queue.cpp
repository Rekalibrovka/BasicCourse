#include "queue.hh"
#include <iostream>
#include <string>

using namespace std;


Queue::Queue(): first_ptr_{nullptr}, last_ptr_{nullptr} {
}


Queue::~Queue() {
   while ( first_ptr_ != nullptr ) {
      Cell* remove_ptr = first_ptr_;
      first_ptr_ = first_ptr_->next_ptr;

      delete remove_ptr;
   }
}


void Queue::print() const {
   Cell *print_ptr = first_ptr_;
   int running_number = 1;

   while ( print_ptr != nullptr ) {
      cout << running_number << ". " << print_ptr->patient_name << endl;

      ++running_number;
      print_ptr = print_ptr->next_ptr;
   }
}


void Queue::add_to_end(const string& new_patient_name) {
    Cell *new_cell_ptr = new Cell;

    new_cell_ptr->patient_name = new_patient_name;
    new_cell_ptr->next_ptr = nullptr;

    if ( first_ptr_ == nullptr ) {
        first_ptr_ = new_cell_ptr;
        last_ptr_ = new_cell_ptr;
    } else {
        last_ptr_->next_ptr = new_cell_ptr;
        last_ptr_ = new_cell_ptr;
    }
}


bool Queue::remove_from_front(string& removed_patient_name) {
   if ( is_empty() ) {
      return false;
   }

   Cell *remove_ptr = first_ptr_;

   removed_patient_name = remove_ptr->patient_name;

   if ( first_ptr_ == last_ptr_ ) {
      first_ptr_ = nullptr;
      last_ptr_ = nullptr;
   } else {
      first_ptr_ = first_ptr_->next_ptr;
   }

   delete remove_ptr;

   return true;
}

void Queue::remove(string removed_patient_name) {

    Cell *prev_ptr = first_ptr_;
    Cell *current_ptr = first_ptr_->next_ptr;

    while (current_ptr != nullptr) {
        if (current_ptr->patient_name == removed_patient_name) {
            break;
        } else {
            prev_ptr = current_ptr;
            current_ptr = current_ptr->next_ptr;
        }
    }

    if(current_ptr == nullptr) { // if we reached end of list or the list is empty
        cout << "Can't remove " << removed_patient_name << ": no match found." << endl;
    } else {
        cout << "Deleting: " << current_ptr->patient_name << endl;
        prev_ptr->next_ptr = current_ptr->next_ptr; // unlink the node you remove
        delete current_ptr; // delete the node
    }
    //delete prev_ptr;
}

bool Queue::is_empty() const {
    // if ( first_ptr_ == nullptr ) {
    //    return true;
    // } else {
    //    return false;
    // }

    // Smarter way to express the same:
    return first_ptr_ == nullptr;
}
