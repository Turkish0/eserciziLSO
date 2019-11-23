#include<stdio.h>
#include<stdlib.h> /* per exit */
#include<unistd.h>
#include<errno.h>
#include <sys/types.h> /* open, lseek */
#include <sys/stat.h>  /* open */
#include <fcntl.h>     /* open */

/*Scrivere un programma che mostra il contenuto 
di un file a byte alterni 
il path del file deve essere passato da riga di comando 

LINK TRACCIA: http://wpage.unina.it/alberto.finzi/didattica/LSO/materiale/Esercitazione_System_Call_I_O.pdf
PAGINA: 37
*/
int main(int argc, char **argv){
    char buffer[10];
    int fileDescriptor;

    if(argc < 2){
        printf("Errore, uso: ./comando <file>\n");
        exit(1);
    }
    //ottieni il file Descriptor con un open
    if( (fileDescriptor = open(argv[1], O_RDONLY) ) < 0 )
        perror("Impossibile aprire il file");

    //finchè non arrivi alla fine del file (read ritorna 0)
    //continua a leggere da fileDescriptor 1 carattere alla 
    //volta inserendolo in buffer
    while( read(fileDescriptor, buffer , 1) != 0  ){
        printf("%c ", buffer[0] );
        //sposta l'offset avanti di 1
        lseek(fileDescriptor, 1, SEEK_CUR );
    }

    printf("\nFine lettura\n");
    return 0;
}
