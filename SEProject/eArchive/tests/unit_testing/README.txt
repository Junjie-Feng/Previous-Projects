Unit testing contains three parts:

---- part 1 ----
emotional_testing.py

This is the python program for testing emotional analysis using TextBlob API.

To install the TextBlob library, please see the website below for instruction.
http://textblob.readthedocs.org/en/dev/install.html

After installed the TextBlob library, ran emotional_testing.py to test emotional analysis on your computer.

---- part 2 ----

We use Python-NLTK to processs each word in the sentence. Before run the program, you should install python and the necessary kit. After that, you should copy data into the specific fold indicated in the program. you can also find the sample data in the fold. 
More information about Python and NLTK, please search 
 http://docs.python.org/
 http://www.nltk.org/

---- part 3 ----

 We use SVM (support vector machine) to categorize every tweeter into two categories. SVM is an advanced technology using training data to build model to predict the incoming data.We use libsvm for SVM implementation. For more information, you should search at 
http://www.csie.ntu.edu.tw/


---- addition ----

These two SVM unit are complete c++ project, which can be run in Visual Studio 2010 or higher version.

1, to predict the testing data, you should creat model using SVM model prediction part first

2, all the model and testing data should be precessed and change the word character, please see the demo1 and report for detailed information, or the accuracy may decrease badly.

3, Please change or delete the sql part code in SVM prediction part if you do not want to connect and database. 

4, You can feel free to change the parameter in SVM model creation part to see if you have any better accuracy.