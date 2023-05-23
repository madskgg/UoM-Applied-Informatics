#include <stdio.h>
#include <stdlib.h>

#define HMax 10             
#define VMax 30            
#define EndOfList -1       

typedef struct {
    char name[21];
    int status;
} ListElementType; 

typedef int KeyType;

typedef struct {
    KeyType RecKey;
    ListElementType Data;
    int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   
    int Size;               
	int SubListPtr;         
    int StackPtr;           
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

const char* UserTypeNames[] = {
    "student",
    "postgraduate student",
    "teacher",
    "visitor"
};

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);

void Print_HashList(HashListType HList);

int main() {
    HashListType HList;
    ListElm AnItem;
    KeyType AKey;
    int Loc, Pred;
    char ch;

    //1
    CreateHashList(&HList);

    //2
    do {
        printf("Enter user's key: ");
        scanf("%d", &AnItem.RecKey);
        printf("Enter user's name: ");
        scanf("%s", AnItem.Data.name);
        printf("Enter user's position (1 = student, 2 = postgraduate student, 3 = teacher, 4 = visitor): ");
        scanf("%d", &AnItem.Data.status);

        AddRec(&HList, AnItem);

        printf("\nContinue Y/N: ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');

    //3
    do {
        printf("Enter user's key for deleting in the Hash: ");
        scanf("%d", &AKey);

        DeleteRec(&HList, AKey);

        printf("\nContinue Y/N: ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');

    //4
    do {
        printf("Enter user's key for searching in the Hash: ");
        scanf("%d", &AKey);

        SearchHashList(HList, AKey, &Loc, &Pred);
        if (Loc != -1) {
        printf("[%d, %s, %s", HList.List[Loc].RecKey, HList.List[Loc].Data.name, UserTypeNames[HList.List[Loc].Data.status - 1]);
        printf("]\n");
    } else {
            printf("There is no user with code %d\n", AKey);
        }

        printf("\nContinue Y/N: ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');

    //5
    Print_HashList(HList);

    return 0;
}

int HashKey(KeyType Key)
{
	return Key%HMax;
}

void CreateHashList(HashListType *HList)
{
	int index;

	HList->Size=0;          
	HList->StackPtr=0;       

	for (index=0;index<HMax;index++)
	{
		HList->HashTable[index]=EndOfList;
    }

	for(index=0;index < VMax-1;index++)
	{
		HList->List[index].Link=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].RecKey==KeyArg)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}

void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
{
	int Loc, Pred, New, HVal;

	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %d \n",DelKey);
	}
}

void Print_HashList(HashListType HList) {
    int i, SubIndex;
    printf("USERS:\n");
    for (i = 0; i < HMax; i++) {
        SubIndex = HList.HashTable[i];
        if (SubIndex != EndOfList) {
            printf("Synonyms, collision at position: %d\n", i);
            while (SubIndex != EndOfList) {
                printf("%d: [%d, %s, %s]\n", SubIndex, HList.List[SubIndex].RecKey, HList.List[SubIndex].Data.name, UserTypeNames[HList.List[SubIndex].Data.status - 1]);
                SubIndex = HList.List[SubIndex].Link;
            }
        }
    }
}




