#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int* ImportMatrice( char fileName[32] )
{
    FILE *myFile = fopen(fileName , "r");
   
    int* mat = malloc(12*sizeof(int));

    char stringLine[32];
    
    int* mati = mat;

    while (fscanf( myFile, "%d %d %d %d\n", mati+0, mati+1, mati+2, mati+3) != EOF)
    {
        mati = mati + 4;
    }
    return mat;
}

int* AdditionMatrice(int *mata, int *matb)
{
    int offset;
    int *matres;

    // addition des valeurs des matrices M1 et M2 -> M3
    for (offset=0; offset < 12; offset++)
    {
        // etape à paralléliser
        *(matres+offset) = *(mata+offset) + *(matb+offset);
    }
    return matres;
}

void AffichageMatrice(int *mat)
{
    int* mati = mat;
    int ligne;

    // afficher la matrice ligne à ligne vers la sortie standard
    for (ligne=0; ligne < 3; ligne++)
    {
        printf("%d %d %d %d\n" , *(mati+0), *(mati+1), *(mati+2), *(mati+3) );
        mati = mati + 4;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int* mat1 = malloc(12*sizeof(int));
    int* mat2 = malloc(12*sizeof(int));
    int* mat3 = malloc(12*sizeof(int));

    mat1 = ImportMatrice("../../texte/matrice1.txt");
    mat2 = ImportMatrice("../../texte/matrice2.txt");

    mat3 = AdditionMatrice(mat1, mat2);

    AffichageMatrice(mat1);
    AffichageMatrice(mat2);
    AffichageMatrice(mat3);
    
    FILE* in_file = NULL;
    in_file = fopen("main_res.txt", "w+");
    if (in_file != NULL)
    { 
        fputs("salut", in_file);
        fclose(in_file);
    }
    return 0;
}
