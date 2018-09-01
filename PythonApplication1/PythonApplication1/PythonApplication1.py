import random
import numpy as np
#инециализация внешней матрицы
def Create_Mat(n):
    Mat=np.array([[random.randint(0,100) for i in range(n)] for i in range(n)])
    return Mat
def Get_Ext(Mat,i,j):
    return Mat[i][j];
n=int(input("ввидите размер матриц\n"))
#внешние матрицы(от external, так как get out - это выйти)
ExtMat1=Create_Mat(n)
ExtMat2=Create_Mat(n)
ExtMat3=np.array([[0 for i in range(n)] for i in range(n)])
y=int(input("выводить внешние матрицы (1 или 0)\n"))
if y==1:
    for i in ExtMat1:
        for j in i:
            print(j,end=' ')
        print("\n",end='');
    print("\n",end='');
    for i in ExtMat2:
        for j in i:
            print(j,end=' ')
        print("\n",end='');
    print("\n",end='');
MAC=int(input("Ввидите количество ядер\n"))
for i in range(n):
    Counter=0;
    while Counter<n:
        #элемент матрицы которая идёт на выход.
        Mi=np.array([0 for i in range(MAC)])
        #тут можно использовать многопоточность,но будут проблемы с реализацией
        for k in range(Counter,min(Counter+MAC,n)):
            #тут точно можно использовать многопоточность
            for j  in range(n):
                #тут на запрос 2 обращение к внешний памяти, 1 перемножение и 1 сложение
                Mi[k-Counter]+=Get_Ext(ExtMat1,i,j)*Get_Ext(ExtMat2,j,k)
            #здесь мы придерживаемся потоки чтобы вывести
            ExtMat3[i][k]=Mi[k-Counter]
        Counter+=MAC
for i in ExtMat3:
    for j in i:
        print(j,end=' ')
    print("\n",end='');
print("\n",end='');
#можно рассмотреть случаи когда хеш<n, тогда многопоточность упрётся в сам хеш