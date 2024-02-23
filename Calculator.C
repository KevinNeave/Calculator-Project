#include <stdio.h>
#include <math.h>

char menu(void){
  int check = 1;
  char option = '0';
  while (check == 1){
    printf("Select one of the following options: \n");
    printf("B) - Binary operations, such as addition and subtraction. \n");
    printf("U) - Unary operations, such as square root and log. \n");
    printf("A) - Advanced operations, using variables. \n");
    printf("V) - Define variables and assign them values. \n");
    printf("E) - Exit \n");
    scanf(" %c", &option);
    if (option == 'B' || option == 'b'){
      check = 0;
    }
    else if (option == 'u' || option == 'U'){
      check = 0;
    }
    else if (option == 'A' || option == 'a'){
      check = 0;
    }
    else if (option == 'V' || option == 'v'){
      check = 0;
    }
    else if (option == 'E' || option == 'e'){
      check = 0;
    }
    else{
      printf("Invalid input. \n");
    }
  }
  return option;
}

float binary (float num1, float *num2, char *operation){
  float result = 0;
  int flag1 = 1;
    while (flag1 == 1){
      switch(*operation){

        case '+':
          result = num1 + *num2;
          flag1 = 0;
          break;

        case '-':
          result = num1 - *num2;
          flag1 = 0;
          break;

        case '*':
          result = num1 * *num2;
          flag1 = 0;
          break;

        case '/':
          if (*num2 == 0){
            printf("Cannot complete operation with 0. Enter a different second number: \n");
            if ((scanf("%f", &*num2)) != 1 || (getchar() != '\n')){
              printf("Invalid number: \n");
                if (getchar() != '\n'){
                  printf("Enter a valid number: \n");
                  scanf("%f", &*num2);
                }
            }
          }
          else{
            result = num1 / *num2;
            flag1 = 0;
          }
          break;

        case '%':
          if (*num2 == 0){
            printf("Cannot complete operation with 0. Enter a different second number: \n\n");
            if ((scanf("%f", &*num2)) != 1 || (getchar() != '\n')){
              printf("Invalid number: \n");
                while (getchar() != '\n'){
                  printf("Enter a valid number: \n");
                  scanf("%f", &*num2);
                }
            }
          }
          else{
            result = remainderf(num1,*num2);
            flag1 = 0;
          }
          
          break;

        case 'P':
        case 'p':
          result = powf(num1,*num2);
          flag1 = 0;
          break;

        case 'X':
        case 'x':
          if (num1 >= *num2){
            result = num1;
          }
          else{
            result = *num2;
          }
          flag1 = 0;
          break;

        case 'I':
        case 'i':
          if (num1<=*num2){
            result = num1;
          }
          else{
            result = *num2;
          }
          flag1 = 0;
          break;

        default:
          printf("Invalid operation please select a valid operation\n");
        printf("Enter the operation (+, -, *, /, %, P, X, I)\n P - power\n X - maximum\n I - minimum\n");
        scanf (" %c", &*operation);
      }
    }
    return result;
  }

float unary (char *operation, float *num){
  int flag2 = 1;
  float result = 0;
  while (flag2 == 1){
    switch (*operation){

      case 'S':
      case 's':
        if (*num<0){
          printf("Cannot complete operation with negative number.\n");
          printf("Enter a non negative number: \n");
          if ((scanf("%f", &*num)) != 1 || (getchar() != '\n')){
            printf("Invalid number: \n");
             while (getchar() != '\n'){
               printf("Enter a valid number: \n");
               scanf("%f", &*num);
            }
          }
        }
        else{
          result = sqrt(*num);
          flag2 = 0;
        }
        break;

      case 'L':
      case 'l':
        if (*num<0){
          printf("Cannot complete operation with negative number.\n");
          printf("Enter a non negative number: \n");
          if ((scanf("%f", &*num)) != 1 || (getchar() != '\n')){
            printf("Invalid number: \n");
             while (getchar() != '\n'){
               printf("Enter a valid number: \n");
               scanf("%f", &*num);
            }
          }
        }
        else{
          result = log(*num);
          flag2 = 0;
        }
        break;

      case 'E':
      case 'e':
        result = exp(*num);
        flag2 = 0;
        break;

      case 'C':
      case 'c':
        result = ceil(*num);
        flag2 = 0;
        break;

      case 'F':
      case 'f':
        result = floor(*num);
        flag2 = 0;
        break;

      default:
        printf("Invalid operation. Please select a valid operation. \n");
        printf("Enter the operation (S, L, E, C, F) \nS - Square root\nL - Logarithm base e\nE - Exponential\nC - Ceiling\nF - floor\n");
        scanf(" %c", &*operation);

    }
  }
  return result;
}

void ext(void){
  printf("Thanks for using my calculator! I hope to see you soon. \n");

}



int main(void) {
  float a, b, c, d, e = 0;
  printf("Welcome to Calculator verson 3.0\n");
  char option = '0';
  while (option != 'E' && option != 'e'){
    option = menu();
    if (option == 'B' || option == 'b'){
      float num1 = 0;
      float num2 = 0;
      float num1r = 0;
      float num2r = 0;
      char operationr = '0';
      float result = 0;
      char operation = '0';
      printf("Enter the first number: ");
      if ((scanf("%f", &num1)) != 1 || (getchar() != '\n')){
        printf("Invalid number. \n");
          while (getchar() != '\n'){
            printf("Enter a valid number: \n");
            scanf("%f", &num1);
          }
      }

      printf("Enter the second number: ");
      if ((scanf("%f", &num2)) != 1 || (getchar() != '\n')){
        printf("Invalid number: \n");
          while (getchar() != '\n'){
            printf("Enter a valid number: \n");
            scanf("%f", &num2);
          }
      }
      printf("Enter the operation (+, -, *, /, %, P, X, I)\n P - power\n X - maximum\n I - minimum\n");
      scanf(" %c", &operation);
      result = binary(num1, &num2, &operation);
      printf("%f %c %f = %f \n", num1, operation, num2, result);
    }
    else if (option == 'U' || option == 'u'){
      float num = 0;
      char operation = '0';
      float result = 0;
      printf("Enter the operation (S, L, E, C, F) \nS - Square root\nL - Logarithm base e\nE - Exponential\nC - Ceiling\nF - floor\n");
      scanf(" %c", &operation);
      printf("Enter a number: \n");

      if ((scanf("%f", &num)) != 1 || (getchar() != '\n')){
        printf("Invalid number: \n");
         while (getchar() != '\n'){
           printf("Enter a valid number: \n");
           scanf("%f", &num);
        }
      }
      result = unary(&operation, &num);
      printf("%c of %.3f = %.3f \n", operation, num, result);
    }
    else if (option == 'A' || option == 'a'){
      char option2 = '0';
      while (option2 != 'E' && option2 != 'e'){
        printf("Select one of the following options that are variable compatible:\nB) - Binary operations, such as addition and subtraction.\nU) - Unary operations such as square root and log.\nE) - Exit to main menu\n");
        scanf(" %c", &option2);

        if (option2 == 'B' || option2 == 'b'){
          float num1 = 0;
          float num2 = 0;
          float result = 0;
          char operation = '0';
          char var1 = '0';
          char var2 = '0';
          int flag6 = 1;
          while (flag6 == 1){
            printf("Enter the first number: ");
            if (scanf("%f", &num1) != 1){
              scanf(" %c", &var1);
              switch(var1){

                case 'A':
                case 'a':
                  num1 = a;
                  flag6 = 0;
                  break;

                case 'B':
                case 'b':
                  num1 = b;
                  flag6 = 0;
                  break;

                case 'C':
                case 'c':
                  num1 = c;
                  flag6 = 0;
                  break;

                case 'D':
                case 'd':
                  num1 = d;
                  flag6 = 0;
                  break;

                case 'E':
                case 'e':
                  num1 = e;
                  flag6 = 0;
                  break;

                default:
                  printf("Invalid input \n");
              }
            }
            else{
              flag6 = 0;
            }
          }

          int flag7 = 1;
          while (flag7 == 1){
            printf("Enter the second number: ");
            if (scanf("%f", &num2)!=1){
              scanf(" %c", &var2);
              switch(var2){

                  case 'A':
                  case 'a':
                    num2 = a;
                    flag7 = 0;
                    break;

                  case 'B':
                  case 'b':
                    num2 = b;
                    flag7 = 0;
                    break;

                  case 'C':
                  case 'c':
                    num2 = c;
                    flag7 = 0;
                    break;

                  case 'D':
                  case 'd':
                    num2 = d;
                    flag7 = 0;
                    break;

                  case 'E':
                  case 'e':
                    num2 = e;
                    flag7 = 0;
                    break;

                  default:
                    printf("Invalid input\n");
              }
            }
            else{
              flag7 = 0;
            }
          }

          printf("Enter the operation (+, -, *, /, %, P, X, I)\n P - power\n X - maximum\n I - minimum\n");
          scanf(" %c", &operation);
          result = binary(num1, &num2, &operation);
          printf("%.3f %c %.3f = %.3f \n", num1, operation, num2, result);
        }
        else if (option2 == 'U' || option2 == 'u'){
          float num = 0;
          char operation2 = '0';
          double result = 0;
          char var = '0';
          printf("Enter the operation (S, L, E, C, F) \nS - Square root\nL - Logarithm base e\nE - Exponential\nC - Ceiling\nF - floor\n");
          scanf(" %c", &operation2);
          printf("Enter a number: \n");
          int flag8 = 1;
          while (flag8 == 1){
            if (scanf("%f",&num)!=1){
              scanf(" %c", &var);
              switch(var){
                
                case 'A':
                case 'a':
                  num = a;
                  flag8 = 0;
                  break;

                case 'B':
                case 'b':
                  num = b;
                   flag8 = 0;
                   break;

                 case 'C':
                 case 'c':
                   num = c;
                   flag8 = 0;
                   break;
                
                case 'D':
                case 'd':
                  num = d;
                  flag8 = 0;
                  break;

                case 'E':
                case 'e':
                  num = e;
                   flag8 = 0;
                   break;

                 default:
                   printf("Invalid input\n");
               }
              }
              else{
                flag8 = 0;
              }
            }
            result = unary(&operation2, &num);
            printf("%c of %.3f = %.3f \n", operation2, num, result);
          }
        else if (option2 == 'E' || option2 == 'e'){
          printf("Exiting to main menu... \n");
        }
        else{
          printf("Invalid input.\n");
        }
      }
    }
    else if (option == 'V' || option == 'v'){
      char var = '0';
      float value = 0;
      printf("Select one of the following variables to set a value to: a, b, c, d, e. \n");
      scanf(" %c", &var);
      printf("Insert the value to assign to the variable: ");
      if ((scanf("%f", &value)) != 1 || (getchar() != '\n')){
        printf("Invalid number. \n");
        while (getchar() != '\n'){
          printf("Enter a valid number: \n");
          scanf("%f", &value);
        }
      }
      int flag5 = 1;
      while (flag5 == 1){
        switch (var){

          case 'A':
          case 'a':
            a = value;
            printf("%.3f assigned to %c \n\n", value, var);
            flag5 = 0;
            break;

          case 'B':
          case 'b':
            b = value;
            printf("%.3f assigned to %c \n\n", value, var);
            flag5 = 0;
            break;

          case 'C':
          case 'c':
            c = value;
            printf("%.3f assigned to %c \n\n", value, var);
            flag5 = 0;
            break;

          case 'D':
          case 'd':
            d = value;
            printf("%.3f assigned to %c \n\n", value, var);
            flag5 = 0;
            break;

          case 'E':
          case 'e':
            e = value;
            printf("%.3f assigned to %c \n\n", value, var);
            flag5 = 0;
            break;

          default:
            printf("Not a valid input \n\n");
            printf("Select one of the following variables to set a value to: a, b, c, d, e. \n");
            scanf(" %c", &var);
        }
      }
    }
    else if (option == 'E' || option == 'e'){
      ext();
    }
    else{
      printf("Not a valid option. reselect an option. \n");
    }
  }
}
