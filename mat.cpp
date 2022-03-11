#include<iostream>

using namespace std;
#include "mat.hpp"
using namespace ariel;
namespace ariel{
   std::string mat (int width, int height, char ch1, char ch2){
       int const minimum_char = 33;
       int const maximum_char = 126;
       // if the number of the coloums or of the rows are even
       if (height%2 == 0 || width%2 == 0) {
            throw runtime_error ("cannot produce the mat because col and row must be odd numbers");
       }

       // if the number of the coloums or of the rows are negative
       if (height < 0 || width < 0 ){
           throw runtime_error("cannot produce the mat because col and row must be positive");
       }

       if (ch1 < minimum_char || ch1 > maximum_char || ch2 < minimum_char || ch2 > maximum_char){
           throw runtime_error("wrong char");
       }
        //memory allocation to the char matrix
        char **matrix = NULL;
        matrix = new char*[height];
        for (int i = 0; i < height; i++)
        {
            matrix[i] = new char[width];
        }
        char current_char = ch1;
        int row=0;
        int col=0;
        int const real_row = height;
        int const real_col = width;

        while (row <= width && col <= height)
        {
            //fill the top row of rectangle
            for (int i = col ; i < width; i++){
                matrix[row][i] = current_char;}
            row++;

            //fill the right colum of rectangle
            for (int i = row ; i < height; i++){
                matrix[i][width-1] = current_char;}
            width--;
            
            //fill the bottom row of rectangle
            if (row <= height){
                for (int i = width; i >= col; i--){
                    matrix[height-1][i] = current_char;}
            }
            height--;

            //fill the left colum of rectangle
            if (col <= width){
                for (int i = height; i >= row; i--){
                    matrix[i][col] = current_char;}
            }
            col++; 

            //change the symbol for the next iteration
            current_char == ch1 ? current_char = ch2 : current_char = ch1; 
        }
        string carpet = "";
        for (int i = 0; i < real_row; i++)
        {
            for (int j = 0; j < real_col; j++)
            {
                carpet += matrix[i][j];
            }
            carpet +="\n";
        }
      //free alocated memory
        for (int i = 0; i < real_row; i++)
        {
            delete[] matrix[i]; //delete all the lines of array
        }
        delete[] matrix; //delete the array
        return carpet;          
    }
    
}
// int main(){
//     cout <<  ariel::mat(9, 7, '@', '-') << endl; 
// }