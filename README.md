# k-nearest-neighbours-c
k-nearest neighbours algorithm programed in c

This is a simple implementation of the k-nearest-neighbours algorithm written in c. The algorithm for classification is based on the euclidean distance between two vectors. First the distance between a new vector and every vector in the datasets is calculated, then the k nearest distances are used to classify the new vector.


# Euclidean Distance

![equation](https://latex.codecogs.com/svg.latex?%5Csqrt%7B%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%28q_i-p_i%29%5E2%7D)

For:

![equation](https://latex.codecogs.com/svg.latex?%5Cbegin%7Bpmatrix%7D%20x_%7B1%7D%20%5C%5C%20y_%7B1%7D%20%5C%5C%20z_%7B1%7D%20%5Cend%7Bpmatrix%7D%20%3D%20%5Cbegin%7Bpmatrix%7D%202%20%5C%5C%203%20%5C%5C%204%20%5Cend%7Bpmatrix%7D)

![equation](https://latex.codecogs.com/svg.latex?%5Cbegin%7Bpmatrix%7D%20x_%7B2%7D%20%5C%5C%20y_%7B2%7D%20%5C%5C%20z_%7B2%7D%20%5Cend%7Bpmatrix%7D%20%3D%20%5Cbegin%7Bpmatrix%7D%205%20%5C%5C%206%20%5C%5C%207%20%5Cend%7Bpmatrix%7D)

d = Distance

![equation](https://latex.codecogs.com/svg.latex?d%20%3D%20%5Csqrt%7B%285-2%29%5E2%20&plus;%20%286-3%29%5E2%20&plus;%20%287-4%29%5E2%7D)

![equation](https://latex.codecogs.com/svg.latex?d%20%3D%20%5Csqrt%7B%283%29%5E2%20&plus;%20%283%29%5E2%20&plus;%20%283%29%5E2%7D)

![equation](https://latex.codecogs.com/svg.latex?d%20%3D%20%5Csqrt%7B9%20&plus;%209%20&plus;%209%7D)

![equation](https://latex.codecogs.com/svg.latex?d%20%3D%20%5Csqrt%7B27%7D)

![equation](https://latex.codecogs.com/svg.latex?d%20%3D%205.196152)
