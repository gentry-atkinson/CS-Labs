//Gentry Atkinson
//CS1428 Fall 2018
//Lab 6

#include <iostream>
#include <fstream>


using namespace std;


int main() {
    // This part is correct!

    fstream dataFile;
    dataFile.open("lab6_data.txt", fstream::in);
    int setSize =  0;
    dataFile >> setSize;

    //After this is broken!

    int data[setSize];
    int counter = 0;
    while (counter < setSize) {
        dataFile >> data[counter];
        counter++;
    }



    //1. DECLARE ANOTHER FILESTREAM TO HANDLE YOUR PROGRAMS OUTPUT
    fstream outFile;
    //2. OPEN FOR OUTPUT THE FILESTREAM WITH THE FILENAME “lab6_output.txt”
    outFile.open("lab6_output.txt", fstream::out);
    //3. DECLARE TWO VARIABLES CALLED maxViews AND minViews
    int maxViews, minViews;
    //4. DECLARE ANOTHER VARIABLE TO TEMPORARILY HOLD VALUES FROM data
    int temp;
    //5. INITIALIZE min WITH A VERY LARGE VALUE. INITIALIZE max WITH A VERY
    //SMALL VALUE
    minViews = 9999999;
    maxViews = 0;
    //6. ENTER A LOOP WHICH WILL COUNT THROUGH THE INDEXES OF data
    for (int i = 0; i < setSize; i++){
        //7. ASSIGN YOUR TEMP VAR TO EQUAL THE VALUE IN THIS INDEX OF data
        temp = data[i];
        //8. IF THE VALUE IN data AT THIS INDEX IS GREATER THAN max,
    //UPDATE max
        if (temp > maxViews) maxViews = temp;
        //9. IF THE VALUE IN data AT THIS INDEX IS SMALLER THAN min,
    //UPDATE min
        if (temp < minViews) minViews = temp;
        //cout << temp << endl;
    //10. EXIT LOOP
    }
    //11. WRITE max AND min INTO THE OUTPUT FILE WITH AN APPROPRIATE LABEL

    outFile << "Max views in one day: " << maxViews << endl;
    outFile << "Min views in one day: " << minViews << endl;




    //declare and initialize counters
    int incCounter=0, decCounter=0;

    //count through every index of data
    for (int i = 1; i < setSize; i++){
        //if larger index has larger value, increment increasing counter
        if (data[i] > data[i-1]) incCounter++;
        //if larger index has smaller value, increment decreasing counter
        else if (data[i] < data[i-1]) decCounter++;
        //no default action
    }

    /****************These two lines are for debugging**************/
    //cout << "Inc: " << incCounter << endl;
    //cout << "Dec: " << decCounter << endl;

    //decide which counter is bigger and write the result to file
    if (incCounter > decCounter) outFile << "This data is generally increasing." << endl;
    else if (incCounter < decCounter) outFile << "This data is generally decreasing." << endl;
    else outFile << "This set neither increases nor decreases" << endl;




    //1. DECLARE VARIABLES OF AN APPROPRIATE TYPE TO HOLD THE SLOPE,
    //Y-INTERCEPT, AND SUM OF ERRORS
    //2. ASSIGN SLOPE VALUE EQUAL TO maxViews - minViews OVER setSize
    float slope = (maxViews - minViews)/ static_cast<float>(setSize);
    //3. USE THE SLOPE AND data[0] TO CALCULATE THE Y-INTERCEPT
    float yIntercept = data[0] - slope;
    float sumOfErrors = 0.0;
    //4. ENTER A LOOP WHICH WILL COUNT THROUGH ALL INDEXES OF data
    for (int i = 0; i < setSize; i++){
        //5. CALCULATE THE DIFFERENCE BETWEEN slope*i + y-intercept AND data[i]
        //6. ADD THIS NUMBER INTO YOUR SUM OR ERRORS.
        sumOfErrors += (i * slope + yIntercept) - data[i];
    } //5. END LOOP

    //6. WRITE THE SLOPE, Y-INTERCEPT, AND SUM OF ERRORS INTO THE OUTPUT
    //FILE WITH APPROPRIATE LABELS.
    outFile << "Slope from linear regression: " << slope << endl;
    outFile << "Y Intercept from linear regression: " << yIntercept << endl;
    outFile << "Sum of errors: " << sumOfErrors << endl;

    outFile.close();
    dataFile.close();

    return 0;
}


