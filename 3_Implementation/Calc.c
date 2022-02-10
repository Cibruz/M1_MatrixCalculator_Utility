int main () {
  printf( "Welcome to Matrix Calculator V1.1 By Baraa Hamodi!\n\n"
    "Start by making your first matrix!\n");
  Matrix a;
  a.getInput();
  int choice;
  string proceed, remakeMatrix;
  cout << "Now that you have this matrix:\n";
  a.displayMatrix();
  printf("What would you like to do?\n""Enter 1 for matrix scalar multiplication.\n"
    "Enter 2 for matrix addition.\n"
    "Enter 3 for matrix multiplication.\n"
    "Enter 4 to find the matrix determinant.\n"
    "Enter 5 to transpose the matrix.\n"
    "Enter 6 to find the inverse of your matrix.\n"
    "Enter 7 to put your matrix in RREF.\n");
  do {
    cout << "Please enter your operation choice: ";
    cin >> choice;
    if (choice == 1) {
      a.scalarMultiplication();
    } else if (choice == 2) {
      cout << "This will require a second matrix, please create one now.\n";
      Matrix b;
      b.getInput();
      a.matrixAddition(b);
    } else if (choice == 3) {
      cout << "This will require a second matrix, please create one now.\n";
      Matrix b;
      b.getInput();
      a.matrixMultiplication(b);
    } else if (choice == 4) {
      a.determinantFinder();
    } else if (choice == 5) {
      a.transpose();
    } else if (choice == 6) {
      a.inverseMatrix();
    } else if (choice == 7) {
      a.matrixRREF();
    }
    cout << "Continue? (Enter yes or no) ";
    cin >> proceed;
    transform(proceed.begin(), proceed.end(), proceed.begin(), ::tolower);
    if (proceed == "yes") {
      cout << "Now enter yes to create a new matrix or no to use current matrix.\n";
      cin >> remakeMatrix;
      transform(remakeMatrix.begin(), remakeMatrix.end(), remakeMatrix.begin(), ::tolower);
      if (remakeMatrix == "yes") {
        a.getInput();
      }
    }
  } while(proceed == "yes");

  system("PAUSE");
  return EXIT_SUCCESS;
}