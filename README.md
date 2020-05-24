# k-nearest-neighbours-c
k-nearest neighbours algorithm programed in c

This is a simple implementation of the k-nearest-neighbours algorithm written in c. The algorithm for classification is based on the euclidean distance between two vectors. First the distance between a new vector and every vector in the datasets is calculated, then the k nearest distances are used to classify the new vector.


# euclidean Distance
<img src="http://www.sciweavers.org/tex2img.php?eq=%20%5Csqrt%7B%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%28q_i-p_i%29%5E2%7D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt=" \sqrt{\sum_{i=1}^{n}(q_i-p_i)^2}" width="117" height="68" />

For:
(X1, Y1, Z1) = (2, 3, 4)
(X2, Y2, Z2) = (5, 6, 7)

d = Distance

<img src="http://www.sciweavers.org/tex2img.php?eq=d%20%3D%20%20%5Csqrt%7B%285-2%29%5E2%20%2B%20%286-3%29%5E2%20%2B%20%287-4%29%5E2%7D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="d =  \sqrt{(5-2)^2 + (6-3)^2 + (7-4)^2}" width="287" height="26" />

<img src="http://www.sciweavers.org/tex2img.php?eq=d%20%3D%20%20%5Csqrt%7B%283%29%5E2%20%2B%20%283%29%5E2%20%2B%20%283%29%5E2%7D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="d =  \sqrt{(3)^2 + (3)^2 + (3)^2}" width="194" height="26" />

<img src="http://www.sciweavers.org/tex2img.php?eq=d%20%3D%20%20%5Csqrt%7B9%20%2B%209%20%2B%209%7D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="d =  \sqrt{9 + 9 + 9}" width="125" height="26" />

<img src="http://www.sciweavers.org/tex2img.php?eq=d%20%3D%20%20%5Csqrt%7B27%7D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="d =  \sqrt{27}" width="74" height="26" />

<img src="http://www.sciweavers.org/tex2img.php?eq=d%20%3D%20%205.196152&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="d =  5.196152" width="118" height="15" />
