//Dot product AB ⋅ BC
int dot(int[] A, int[] B, int[] C){
    AB = new int[2];
    BC = new int[2];
    AB[0] = B[0]-A[0];
    AB[1] = B[1]-A[1];
    BC[0] = C[0]-B[0];
    BC[1] = C[1]-B[1];
    int dot = AB[0] * BC[0] + AB[1] * BC[1];
    return dot;
}

//Produto vetorial AB x AC
int cross(int[] A, int[] B, int[] C){
    AB = new int[2];
    AC = new int[2];
    AB[0] = B[0]-A[0];
    AB[1] = B[1]-A[1];
    AC[0] = C[0]-A[0];
    AC[1] = C[1]-A[1];
    int cross = AB[0] * AC[1] - AB[1] * AC[0];
    return cross;
}

//Distância de A para B
double distance(int[] A, int[] B){
    int d1 = A[0] - B[0];
    int d2 = A[1] - B[1];
    return sqrt(d1*d1+d2*d2);
}

//Distância de C para a reta AB, se isSegment é true, AB é um segmento, não uma reta.
double linePointDist(int[] A, int[] B, int[] C, boolean isSegment){
    double dist = cross(A,B,C) / distance(A,B);
    if(isSegment){
        int dot1 = dot(A,B,C);
        if(dot1 > 0)return distance(B,C);
        int dot2 = dot(B,A,C);
        if(dot2 > 0)return distance(A,C);
    }
    return abs(dist);
}

----------------------------------------------------------
//Área de polígonos
int area = 0;
int N = quantidade de pontos no polígono e armazenados em p;
//Triangular o polígono em triângulos com pontos p[0],p[i],p[i+1]

for(int i = 1; i+1<N; i++){
    int x1 = p[i][0] - p[0][0];
    int y1 = p[i][1] - p[0][1];
    int x2 = p[i+1][0] - p[0][0];
    int y2 = p[i+1][1] - p[0][1];
    int cross = x1*y2 - x2*y1;
    area += cross;
}
return abs(cross/2.0);

----------------------------------------------------------
// Intersecção de retas Ax + By = C    dados pontos (x1,y1) e (x2,y2)
A = y2-y1
B = x1-x2
C = A*x1+B*y1

//Retas definidas pelas equações:
A1x + B1y = C1
A2x + B2y = C2

//Encontrar x e y resolvendo o sistema
double det = A1*B2 - A2*B1;
if(det == 0){
    //Lines are parallel
}else{
    double x = (B2*C1 - B1*C2)/det;
    double y = (A1*C2 - A2*C1)/det;
}

