/*#include<iostream>
#define n 4
// code jam matrix
using namespace std;
int main () {
    int A[n][n];
    int B[n][n];
    int C[n][n];
    cout << " inter number for matrix A \n " ;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            cin >> A[i][j] ;
        }
    }
    cout << " inter a number for matrix B \n " ;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            cin>> B[i][j] ;
        }

    }
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            C[i][j] = A[i][j] + B[i][j] ;
        }
    }
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            cout << "\t"<<C[i][j];
        }
        cout << endl << "\n";
    }
}*/
/*#include<iostream>
#define n 4
// code tafrigh matrix
using namespace std;
int main () {
    int A[n][n];
    int B[n][n];
    int C[n][n];
    cout << " inter number for matrix A \n " ;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            cin >> A[i][j] ;
        }
    }
    cout << " inter a number for matrix B \n " ;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            cin>> B[i][j] ;
        }

    }
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            C[i][j] = A[i][j] - B[i][j] ;
        }
    }
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            cout << "\t"<<C[i][j];
        }
        cout << endl << "\n";
    }
}*/
/*#include<iostream>
#define n 4
// code zarb matrix
using namespace std;

int main() {
    int A[n][n];
    int B[n][n];
    int C[n][n] = {{0}};
    cout << " inter number for matrix A \n ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            (int)A[i][j];
        }
    }
    cout << " inter a number for matrix B \n ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
            (int)B[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];

            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "\t\t" << C[i][j];
        }
        cout << endl << "\n";
    }
}*/
/*#include<iostream>
#define n 4
//code taranahadeh matrix
using namespace std;

int main() {
    int A[n][n];
    int B[n][n];
    cout << " inter number for matrix A \n ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           B[i][j]=A[j][i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "\t\t" << B[i][j];
        }
        cout << endl << "\n";
    }
}*/
/*#include<iostream>

#define n 4
//code determinan matrix
using namespace std;

int main() {
    int A[n][n]{{1, 1, 1, 0},
                {1, 2, 1, 3},
                {2, 2, 3, 0},
                {2, 3, 0, 0}};
    int det, det1, det2, det3, det4;

    if (n == 1) {
        det = A[0][0];
    } else if (n == 2) {
        det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    } else if (n == 3) {
        A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
        A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    } else if (n == 4) {
        int det1 = A[0][0] * (A[1][1] * (A[2][2] * A[3][3] - A[3][2] * A[2][3]) -
                              A[1][2] * (A[2][1] * A[3][3] - A[2][3] * A[3][1]) +
                              A[1][3] * (A[2][1] * A[3][2] - A[2][2] * A[3][1]));
        int de2 = A[0][1] * (A[1][0] * (A[2][2] * A[3][3] - A[3][2] * A[2][3]) -
                             A[1][2] * (A[2][0] * A[3][3] - A[2][3] * A[3][0]) +
                             A[1][3] * (A[2][0] * A[3][2] - A[2][2] * A[3][0]));
        int det3 = A[0][2] * (A[1][0] * (A[2][1] * A[3][3] - A[3][1] * A[2][3]) -
                              A[1][1] * (A[2][0] * A[3][3] - A[2][3] * A[3][0]) +
                              A[1][3] * (A[2][0] * A[3][1] - A[2][1] * A[3][0]));
        int det4 = A[0][3] * (A[1][0] * (A[2][1] * A[3][2] - A[3][1] * A[2][2]) -
                              A[1][1] * (A[2][0] * A[3][2] - A[2][2] * A[3][0]) +
                              A[1][2] * (A[2][0] * A[3][1] - A[2][1] * A[3][0]));
        det = det1 - det2 + det3 - det4;
    }
    cout << det;
}*/
