# Playing Card Recognition
A simple console application that segments cards from an image and calculates their value. 

## Introduction
The aim of the project is to sort the cards in the picture by their value (from
the smallest to the largest). The cards were randomly scattered on a black background. The algorithm does not use a priori knowledge (for example, knowledge of the number of cards in the picture or cards size). 

## Features 
The algorithm was tested for the original photo and three modified ones. 

### Input
Picture of the cards (in this case it's the modified one with salt and pepper noise.
![alt text](https://i.imgur.com/RcYygKK.jpg)

### Output 
Segmented cards after the perspective transformation saved in separate files. 
![alt text](https://i.imgur.com/RDJMnWf.png)

And the result printed in the console.
```console
Sorted cards values:
4
5
9
9
```

## Technologies
* Microsoft Visual Studio Community 2019 (Version 16.3.10)
* C++
* OpenCV (Version 4.1.2)

## Sources 
Materials used to create the application.
* https://docs.opencv.org/trunk/d9/d8b/tutorial_py_contours_hierarchy.html
* http://analizaobrazu.x25.pl/articles/11
* Malina W., Smiatcz M. Cyfrowe przetwarzanie obrazów. Wydawnictwo: EXIT.Wydanie: 11.2012
* Bradski G., Kaehler A. Learning OpenCV, O'Reilly Media, 2008
