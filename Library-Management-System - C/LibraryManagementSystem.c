#include <stdio.h>
#include <stdlib.h>

struct reader{            //Define structure reader
    int id;               //id stores reader id
    char name[20];        //name stores reader's name
    char due;               //due stores y/n for if any book is due by particular leader
    int dbid;               //dbid stores due book's id
} rdr[10]={0};              //rdr array is initialised with structure of reader

struct book{                //structure book defined
    int id;                 //id here stores book id
    char name[30];          //name stores name of the book
    char author[20];        //author stores name of the author
    char avbl;              //avbl stores availability of the book as y/n
    int rid;                //rid stores reader id having the book
};							//bk array is initialised with structure of book


void addBook(struct book* bk);								//1
void searchBook(struct book* bk);							//2
void addNewReader(struct reader* rdr);						//3
void searchReader(struct reader* rdr);						//4
void issueBook(struct book* bk, struct reader* rdr);		//5
void subbmitBook(struct book* bk, struct reader* rdr);		//6
void deleteBook(struct book* bk);							//7
void deleteReader(struct reader* rdr);						//8*
void listOfBooks(struct book* bk);							//9


int main(){
	struct book bk[20] = {0}; // initialize the array with all elements set to 0
	struct reader rdr[10] = {0};
	
	int choice, searchid, searchid1, n, m;          //some integer variables are declared to be used for performing different functions in program

    printf("\n\t\tWELCOME!\n");               //Welcome message 

	do{
		printf("\n\tLibrary Management System\n\t=========================\n1. Add new book\t\t2. Search book\n3. Add new reader\t4. Search reader\n5. Issue book\t\t6. Submit book\n7. Delete book\t\t8. Delete reader\n9. List of books\t10. Exit\n\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice){
		case 1: addBook(bk);
			break;
		case 2: searchBook(bk);
			break;
		case 3: addNewReader(rdr);
			break;
		case 4: searchReader(rdr);
			break;
		case 5: issueBook(bk, rdr);
			break;
		case 6: subbmitBook(bk, rdr);
			break;
		case 7: deleteBook(bk);
			break;
		case 8: deleteReader(rdr);
			break;
		case 9: listOfBooks(bk);
			break;
		case 10: 
			printf("\n\t\tTHANK YOU!");
		    exit(0);
			break;
	}
	
	}while(choice != 10);
	return 0;
	
}

//---------------------------FUNCTIONS----------------------------------------
void addBook(struct book* bk){
	int i;
	for(i=0; i<20; i++){
		if (bk[i].id==0){							//to find empty space in bk array
			if (bk[i].id==0){						//to find empty space in bk array
            printf("Enter name of the book: ");
            scanf("%s", bk[i].name);
            printf("Enter name of the author: ");
            scanf("%s", bk[i].author);
            printf("Enter book ID: ");
            scanf("%d", &bk[i].id);
            bk[i].avbl='y';							//set availability to y
            bk[i].rid=0;							//set readers id to 0 as default
            i=20;									//to exit from for loop
            printf("Book added successfully.\n\n");
			}
		}        
	}
}
void searchBook(struct book* bk){
	int searchid, i, n=0;
	printf("Enter book ID: ");
    scanf("%d", &searchid);
    for(i=0; i<20; i++){
        if (searchid == bk[i].id){
        printf("\n\tBook Information\nBook ID: %d\tBook Name: %s\nAuthor Name: %s\nAvailable: %c\tDue by Reader ID: %d\n", bk[i].id, bk[i].name, bk[i].author, bk[i].avbl, bk[i].rid);
        n++;
        }
    }
    if(n==0){
        printf("Book not found.\n\n");
    }
}
void addNewReader(struct reader* rdr){
	int i;
	for(i=0; i<10; i++){        
    if (rdr[i].id==0){                  // to search empty space in rdr array
        printf("Enter Reader's name: ");
        scanf("%s", rdr[i].name);
        printf("Enter Reader id: ");
        scanf("%d", &rdr[i].id);
        rdr[i].due='n';
        rdr[i].dbid=0;
        i=10;
        printf("Reader added successfully.\n\n");
    }
}
}
void searchReader(struct reader* rdr){
	int searchid, n=0, i;
	printf("Enter Reader ID: ");
    scanf("%d", &searchid);
    for(i=0; i<10; i++){
        if (searchid==rdr[i].id){
            printf("\n\tReader Information\nReader ID: %d\tReader Name: %s\nDue: %c\t\tDue book ID: %d\n", rdr[i].id, rdr[i].name, rdr[i].due, rdr[i].dbid);
        n++;
        }
    }
    if(n==0){
        printf("Reader not found.\n\n");
    }   
}
void issueBook(struct book* bk, struct reader* rdr){
	int searchid, searchid1, n=0, m=0, i;
	printf("Enterd book ID: ");
	scanf("%d", &searchid);
	printf("Enterd reader ID: ");
	scanf("%d", &searchid1);
	for(i=0; i<20; i++){
		if (searchid==bk[i].id && bk[i].avbl=='y'){
			bk[i].avbl='n';
			bk[i].rid=searchid1;
			n++;
			i=20;
		}
	}
	for(i=0; i<10; i++){
        if (searchid1==rdr[i].id && rdr[i].due=='n'){
            rdr[i].due='y';
            rdr[i].dbid=searchid;
            m++;
            i=10;
        }
    }
	if(n==1 && m==1){
		printf("Book issued successfully.\n\n");
        }
    else if(n==1 && m==0){
        for(i=0; i<20; i++){
            if (searchid==bk[i].id){
                bk[i].avbl='y';
                bk[i].rid=0;
                i=20;
            }
        }
        printf("Book not issued.\nReader has a due book.\n\n");
    }

}
void subbmitBook(struct book* bk, struct reader* rdr){
	int searchid, searchid1, i;
	printf("Enter book ID: ");
    scanf("%d", &searchid);
    for(i=0; i<20; i++){
        if (searchid==bk[i].id){
            bk[i].avbl='y';
            searchid1=bk[i].rid;
            bk[i].rid=0;
        }
    }
    for(i=0; i<10; i++){
        if (searchid1==rdr[i].id){
            rdr[i].due='n';
            rdr[i].dbid=0;
        }
    }
    printf("Book ID %d submitted successfully.\n\n", searchid);
}
void deleteBook(struct book* bk){
	int searchid, n=0, i;
	printf("Enter book ID to be deleted: ");
    scanf("%d", &searchid);
    for(i=0; i<20; i++){
        if (searchid==bk[i].id){
            for(i=i; i<20; i++){
                bk[i]=bk[i+1];
            }
            n++;
        }
    }
    if(n!=0){
        printf("Book ID %d deleted.\n\n", searchid);
    }
    else
        printf("Book not found.\n\n");
}
void deleteReader(struct book* bk){
	int searchid, n=0, i;
	printf("Enter reader ID to be deleted: ");
    scanf("%d", &searchid);
    for(i=0; i<10; i++){
        if (searchid==rdr[i].id){
            for(i=i; i<10; i++){
                rdr[i]=rdr[i+1];
            }
            n++;
        }
    }
    if(n!=0){
        printf("Reader ID %d deleted.\n\n", searchid);
    }
    else
        printf("Reader not found.\n\n");
}
void listOfBooks(struct book* bk){
	int n=0;
	int i;
    for(i=0; i<20; i++){
        if(bk[i].id != 0){
            n++;
        }
    }
    printf("\n\t\tBook list\tTotal books: %d\n\nID\tName\t\t\tAuthor\t\t\tAvailable\tReader ID\n\n", n);
    for(i=0; i<20; i++){
        if(bk[i].id != 0){
        printf("%d\t%s\t\t%s\t\t%c\t\t%d\n", bk[i].id, bk[i].name, bk[i].author, bk[i].avbl, bk[i].rid);
        }
    }

}
