# k-nearest-neighbours-c
k-nearest neighbours algorithm programed in c

This is a simple implementation of the k-nearest-neighbours algorithm written in c. The algorithm for classification is based on the euclidean distance between two vectors. First the distance between a new vector and every vector in the datasets is calculated, then the k nearest distances are used to classify the new vector.


# euclidean Distance

Formula: <img src="https://bit.ly/3gp5Fwb" align="center" border="0" alt="\sqrt{\sum_{i=1}^{n}(q_i-p_i)^2}" width="117" height="68" />

For:
(X1, Y1, Z1) = (2, 3, 4)
(X2, Y2, Z2) = (5, 6, 7)

d = Distance

1.Step:
<img src="https://bit.ly/2ZA8q7E" align="center" border="0" alt="d = \sqrt{(5-2)^2 + (6-3)^2 + (7-4)^2}" width="287" height="26" />

2.Step:
<img src="https://bit.ly/2LYACcc" align="center" border="0" alt="d = \sqrt{(3)^2 + (3)^2 + (3)^2}" width="194" height="26" />

3.Step:
<img src="https://bit.ly/2zqqiar" align="center" border="0" alt="d = \sqrt{9 + 9 + 9}" width="125" height="26" />

4.Step:
<img src="https://bit.ly/2LTOxAt" align="center" border="0" alt="d = \sqrt{27}" width="74" height="26" />

5.Step:
<img src="https://bit.ly/2AYxZ8j" align="center" border="0" alt="d = 5.196152" width="118" height="15" />
