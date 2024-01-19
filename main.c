#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
//for all the users
struct User
{
    char userFullName[30];
    char userEmail[30];
    char userName[15];
    int age;
    char password[15];
    int payment_status;
    char type_plan;
    int price;
    char resolution[20];
};
//for all the movies
struct Movie
{
    int primary;
    char name[30];
    char length[20];
    char details[50];
    char genre[10];
    int agelimit;
};

struct User *users=NULL; //initial state null
//movie list
struct Movie movies[]=
{

    {1, "Inception", "2h 28min", "A mind-bending heist movie", "Sci-Fi", 13},
    {2, "The Shawshank Redemption", "2h 22min", "Two imprisoned men bond over a number of years", "Drama", 16},
    {3, "The Dark Knight", "2h 32min", "A criminal mastermind known as the Joker", "R-Rated", 18},
    {4, "Pulp Fiction", "2h 34min", "Various interconnected stories of crime", "Crime", 17},
    {5, "Forrest Gump", "2h 22min", "Life is like a box of chocolates", "War", 12},
    {6, "The Godfather", "2h 55min", "A tale of a powerful Italian-American crime family", "R-Rated", 18},
    {7, "The Matrix", "2h 16min", "The world is a simulated reality", "R-Rated", 16},
    {8, "Jurassic Park", "2h 7min", "Dinosaurs brought back to life", "Action", 10},
    {9, "Titanic", "3h 14min", "A romance set against the sinking of the Titanic", "Drama", 14},
    {10, "The Lion King", "1h 28min", "A young lion prince's journey to adulthood", "R-Rated", 16},
    {11, "The Avengers", "2h 23min", "A group of superheroes team up to save the world", "Action", 12},
    {12, "Interstellar", "2h 49min", "A group of explorers travels through a wormhole in space", "Sci-Fi", 14},
    {13, "The Social Network", "2h", "The founding and rise of Facebook", "Drama", 15},
    {14, "Inglourious Basterds", "2h 33min", "A group of Jewish U.S. soldiers plot to kill Nazis", "R-Rated", 18},

};

int usercount=0; //initial use 0
//using for dynamic memory
void resizearray()
{
    users=realloc(users, (usercount + 1) * sizeof(struct User));
    if(users==NULL)
    {
        printf("Memory Allocation Error!\n");
        exit(EXIT_FAILURE);
    }

}
//for registartion
void registerUserInput(char userFullName[30],char userEmail[30],char userName[15], int age,char password[15])
{


    resizearray();

    snprintf(users[usercount].userFullName,sizeof(users[usercount].userFullName),"%s",userFullName);
    snprintf(users[usercount].userEmail,sizeof(users[usercount].userEmail),"%s",userEmail);
    users[usercount].age=age;
    snprintf(users[usercount].userName,sizeof(users[usercount].userName),"%s",userName);
    snprintf(users[usercount].password,sizeof(users[usercount].password),"%s",password);
    usercount++;

}


//payment function
int payment()
{

    char typePlan;
    char resolution[20];
    int price;
    printf("Choose the plan that's right for your.\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t|Watch all you want. Ad-free. | \n\t|Recommendations just for you.|");
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
    printf("Type of plan[m-Mobile, b-Basic, s-Standard, p-Premium]: ");
    scanf(" %c", &typePlan);

        if(typePlan=='m')
    {
        price=17;
        users[usercount - 1].type_plan = typePlan;
        users[usercount - 1].price = price;
        strcpy(resolution, "480px");

        strcpy(users[usercount - 1].resolution, resolution);
         printf("\n");
        printf("Device you can use to watch: \n\t--------\n\t|Phone | \n\t|Tablet|");
        printf("\n\t--------\n");
    }

    else if(typePlan=='b')
    {
        price=28;
        strcpy(resolution, "720px");
        users[usercount - 1].type_plan = typePlan;
        users[usercount - 1].price = price;
        strcpy(users[usercount - 1].resolution, resolution);
         printf("\n");

        printf("Device you can use to watch: \n\t----------\n\t|Phone   | \n\t|Tablet  | \n\t|Computer| \n\t|TV      |");
        printf("\n\t----------\n");
    }

    else if(typePlan=='s')
    {
        price=45;
        strcpy(resolution, "1080px");
        users[usercount - 1].type_plan = typePlan;
        users[usercount - 1].price = price;
        strcpy(users[usercount - 1].resolution, resolution);
        printf("\n");
       printf("Device you can use to watch: \n\t----------\n\t|Phone   | \n\t|Tablet  | \n\t|Computer| \n\t|TV      |");
        printf("\n\t----------\n");
    }
    else if(typePlan=='p')
    {
        price=55;
        strcpy(resolution, "4K+HDR");
        users[usercount - 1].type_plan = typePlan;
        users[usercount - 1].price = price;
        strcpy(users[usercount - 1].resolution, resolution);
         printf("\n");
        printf("Device you can use to watch: \n\t----------\n\t|Phone   | \n\t|Tablet  | \n\t|Computer| \n\t|TV      |");
        printf("\n\t----------\n");
    }

    else
    {
        printf("\n");
        printf("Input Validation Error!!\n");
    }
    printf("\n");
    char card[20];
    printf("Enter Your Card Details: ");
    scanf("%s",card);
    printf("\n\tWait a Moment......\n");
    printf("\tYour Payment Is Complete\n\tFind Your Payment Details At Your Email \n%s\n",users[usercount-1].userEmail);
    users[usercount-1].payment_status=1;
    printf("\n");
     }



//authentication check
int login(char Inputusername[15],char Inputuserpassword[15])
{
    for(int i=0;i<usercount;i++)
    {
        if(strcmp(Inputusername,users[i].userName)==0 && strcmp(Inputuserpassword,users[i].password)==0)
        {
            return 1;
        }
    }
    return 0;
}
//personal details

void personalDetails(char userName[],char password[])
{
    for(int i=0;i<usercount;i++)
    {
        if(strcmp(users[i].userName,userName)==0 && strcmp(users[i].password,password)==0)
        {
            printf("\n");
            printf("// -----YOUR PERSONAL INFORMATION----- //\n");
            printf("Full Name: %s",users[i].userFullName);
            printf("\nUser Name: %s",users[i].userName);
            printf("\nEmail: %s",users[i].userEmail);
            printf("\nUser Age: %d",users[i].age);
            printf("\nYou Are Watching Movie In: %s\n",users[i].resolution);
            printf("You Purchased: %c Package\n",users[i].type_plan);
            printf("You Paid So Far: RM%d\n",users[i].price);
             printf("\n");

        }
    }
}
//reccomendation
void recommendation(char Inputusername[],int age)
{
    for(int i=0;i<sizeof(movies)/sizeof(movies[0]);i++)
    {
    if(age>=18)
    {
            printf("Movie %d\n", i + 1);
            printf("Name: %s\n", movies[i].name);
            printf("Length: %s\n", movies[i].length);
            printf("Details: %s\n", movies[i].details);
            printf("Genre: %s\n", movies[i].genre);
            printf("-----------------------------------------------\n");
            printf("\n");
    }
    else if(age<18)
    {
        if(strcmp(movies[i].genre,"R-Rated")==0)
        {
            continue;
        }
            printf("Movie %d\n", i + 1);
            printf("Name: %s\n", movies[i].name);
            printf("Length: %s\n", movies[i].length);
            printf("Details: %s\n", movies[i].details);
            printf("Genre: %s\n", movies[i].genre);
            printf("-----------------------------------------------\n");
            printf("\n");
    }
    }
}
//showing movie
void movieShow(option)
{
    printf("\nGreat Choice!Enjoy Watching The Movie\n");
    printf("+-------------------------------------------+\n");
    printf("|                                           |\n");
    printf("|           Movie is Playing Here           |\n");
    printf("|                                           |\n");
    printf("+-------------------------------------------+\n");
    printf("\n");
    printf("You Can Also Watch Similar Movies\n");
    printf("\n");
}

void recommendation_show(int option)
{

    for(int i=0;i<sizeof(movies)/sizeof(movies[0]);i++)
    {
        if(movies[i].primary == option)
        {
            char movie_genre[10];
            strcpy(movie_genre,movies[i].genre);
            for(int j=0;j<sizeof(movies)/sizeof(movies[0]);j++)
            {
            if(strcmp(movies[j].genre,movie_genre)==0 && option!=movies[j].primary)
            {
            printf("\n");
            printf("----------------------------------------------------------\n");
            printf("Movie   1: %d\n", j + 1);
            printf("Name    : %s\n", movies[j].name);
            printf("Length  : %s\n", movies[j].length);
            printf("Details : %s\n", movies[j].details);
            printf("Genre   : %s\n", movies[j].genre);
            printf("----------------------------------------------------------\n");
            printf("\n");
            }
            }
        }
    }
}
void see_movies_genre(char selection_genre[])
{

    for(int i=0;i<sizeof(movies)/sizeof(movies[0]);i++)
    {
        if(strcmp(selection_genre,movies[i].genre)==0)
        {

            printf("----------------------------------------------------------\n");
            printf("Movie   : %d\n", i + 1);
            printf("Name    : %s\n", movies[i].name);
            printf("Length  : %s\n", movies[i].length);
            printf("Details : %s\n", movies[i].details);
            printf("Genre   : %s\n", movies[i].genre);
            printf("----------------------------------------------------------\n");
            printf("\n");
        }
    }
    }


void genre(char Inputusername[],int age)
{
    if(age>=18)
    {
        printf("\n");
        printf("============================================================================================\n");
        printf("\tN.B. YOUR AGE IS ABOVE OR EQUAL 18 THAT IS WHY R-RATED MOVIES ARE VISIBLE FOR YOU,\n\tIF LESS THAN 18 YOU WOULD NOT SEE THE OPTION.\n");
        printf("============================================================================================\n");;
        printf("Select Any Option: \n1.Drama\n2.R-Rated\n3.Action\n4.War\n5.Sci-Fi\n");
        getchar();
        char selection_genre[15];
        int option;
        scanf("%d",&option);
        if(option==1)
        {
            strcpy(selection_genre,"Drama");
            see_movies_genre(selection_genre);
        }
        else if(option==2)
        {
            strcpy(selection_genre,"R-Rated");
            see_movies_genre(selection_genre);
        }
        else if(option==3)
        {
            strcpy(selection_genre,"Action");
            see_movies_genre(selection_genre);
        }
        else if(option==4)
        {
            strcpy(selection_genre,"War");
            see_movies_genre(selection_genre);
        }
        else if(option==5)
        {
            strcpy(selection_genre,"Sci-Fi");
            see_movies_genre(selection_genre);
        }
        else{
            printf("Try Again!!\n");
        }

    }
    else if(age<18)
    {
        printf("\n");
        printf("N.B. YOUR AGE LESS 18 THAT IS WHY R-RATED MOVIES ARE NOT VISIBLE FOR YOU,\nIF GREATER OR EQUAL THAN 18 YOU WOULD SEE THE GENRE TOO\n");
        printf("Select Any Option\n1.Drama\n2.Action\n3.War\n4.Sci-Fi\n");
        printf("\n");
        int option;
        scanf("%d",&option);
        char selection_genre[15];
        if(option==1)
        {
            strcpy(selection_genre,"Drama");
            see_movies_genre(selection_genre);
        }

        else if(option==2)
        {
            strcpy(selection_genre,"Action");
            see_movies_genre(selection_genre);
        }

        else if(option==3)
        {
            strcpy(selection_genre,"War");
            see_movies_genre(selection_genre);
        }

        else if(option==4)
        {
            strcpy(selection_genre,"Sci-Fi");
            see_movies_genre(selection_genre);

        }
        else
        {
            printf("Error!Try Again");
        }

    }
    else
    {
        printf("\n");
        printf("Input Validation Error!\n");
    }
}


void generate_report()
{
    FILE *fptr;
    fptr = fopen("report.txt", "w");

    if (fptr == NULL)
    {
        printf("Error opening file for writing\n");
        return;
    }

    int total_users = 0;
    int total_money = 0;

    for (int i = 0; i < usercount; i++)
    {
        total_users++;
        total_money += users[i].price;
    }

    fprintf(fptr, "********** Netflix Video Streaming Platform Report **********\n");
    fprintf(fptr, "Total Registered Users: %d\n", total_users);
    fprintf(fptr, "Total Money Earned: RM%d\n", total_money);

    fclose(fptr);
    printf("Report generated successfully. Check 'report.txt' In Your Local Machine\n");
    printf("\n");
}



int main()
{
    char userFullName[30];
    char userEmail[30];
    char userName[15];
    int age;
    char password[15];
    char Inputusername[15];
    char Inputuserpassword[15];
    char admin_user_name[15];
    char admin_password[15];


    printf("-------------Welcome To Netflix Video Streaming Platform-------------");
    printf("\n");
    while(true)
    {
    printf("Choose Any Option:\n1.Registration\n2.Login\n");
    int decision;
    scanf("%d",&decision);
    getchar();
        if(decision==1)
    {
            printf(" -------------PLEASE FILL IN ALL THE DETAILS BELOW---------------");
    printf("\n\nEnter Your FullName   : ");
    fgets(userFullName,30,stdin);
    userFullName[strcspn(userFullName,"\n")]='\0';

    printf("Enter Your Email      : ");
    fgets(userEmail,30,stdin);
    userEmail[strcspn(userEmail,"\n")]='\0';

    printf("Enter Your Age        : ");
    scanf("%d",&age);
    getchar();

    printf("Set Your User Name    : ");
    fgets(userName, 15, stdin);
    userName[strcspn(userName, "\n")] = '\0';

    printf("Set Your Password     : ");
    fgets(password,15,stdin);
    password[strcspn(password,"\n")]='\0';
        printf("\n");
        registerUserInput(userFullName,userEmail,userName,age,password);
        printf("\n");
        printf("Details Saved!\n");
        printf("\n");
        payment();


    }
    else if(decision==2)
    {
        printf("\n");
        printf("Login As: \n1.Admin\n2.User\n");
        int decision2;
        scanf("%d",&decision2);
        if(decision2==2)
        {
            printf("\n*******Enter Your Login Credentials Here*******\n");
            printf("\n");
            printf("Enter Your Username  : ");
            scanf("%s",&Inputusername);

            printf("Enter Your Password  : ");
            scanf("%s",&Inputuserpassword);

            int auth=0;
            if(login(Inputusername,Inputuserpassword)==1)
            {
                auth=1;
                printf("\n\nAuthentication Successful: \n");
                while(auth=1)
                {
                printf("\n");

                printf("1. Search Movie By Genre\n2. See All Available Movies\n3. User Information\n4. Logout\n");

                int decision3;
                scanf("%d",&decision3);
                if(decision3==1)
                {
                    for(int i=0;i<usercount;i++)
                    {
                        if(strcmp(users[i].userName,Inputusername)==0 && strcmp(users[i].password,Inputuserpassword)==0)
                        {
                            int user_age=users[i].age;
                            genre(Inputusername,user_age);
                        }
                    }

                }else if(decision3==2)
                {
                    printf("\n// Recommended Movies For You //\n[If your age less than 18,then some movies will be exclude from you recommendation]\n");
                    printf("\n");
                    for(int i=0;i<usercount;i++)
                    {
                        if(strcmp(users[i].userName,Inputusername)==0)
                        {
                            users[i].age=age;
                          recommendation(Inputusername,age);
                          printf("\n");
                          printf("Select Any Movie: ");
                          getchar();
                          int option;
                          scanf("%d",&option);
                          movieShow(option);
                          recommendation_show(option);
                        }
                    }

                }
                else if(decision3==3)
                {
                    personalDetails(userName,password);
                }
                else if(decision3==4)
                {
                    printf("Are You Sure\n1.Yes\n2.No\n");
                    int choice;
                    scanf("%d",&choice);
                    if(choice==1)
                    {
                        printf("Logged Out Successfully\n");
                        auth=0;
                        break;
                    }
                    else
                    {
                        printf("\n");
                    }
                }
                }
            }
        }
        else if(decision2==1)
        {
            int auth=0;
            printf("------------Welcome To Admin Login Panel------------\n");
            printf("\n");
            printf("//    Enter Your Admin Login Credential    //\n");
            printf("Enter Your Admin Id [Please Enter admin1* To Login In The Admin Panel]\n");
            printf("\n");
            scanf("%s",admin_user_name);
            printf("Enter Your Admin Password [Please Enter admin1* To Login In The Admin Panel]\n"); //username and pasword is admin1
            scanf("%s",admin_password);
            if(strcmp(admin_user_name,"admin1")==0 && strcmp(admin_password,"admin1")==0)
            {
                printf("\n");
                printf("Authentication Successful\n");
                auth=1;
            while(auth==1)
            {
                printf("\n");
                printf("Welcome To Admin Dashboard\n");
                printf("Select Any Option~\n1.Generate Report\n2.Logout\n");
                getchar();
                int option;
                scanf("%d",&option);
                if(option==1)
                {
                    generate_report();
                }
                else if(option==2)
                {
                    printf("Are You Sure?\n1.Yes\n2.No\n");
                    int choice;
                    scanf("%d",&choice);
                    if(choice==1)
                    {
                    printf("Logged Out From The System\n");
                    printf("\n");
                    auth=0;
                    }
                    else
                    {
                        continue;
                    }

                }
                else
                {
                    printf("Input Error\n");
                     printf("\n");
                    continue;
                }
            }

            }
            else
            {
                printf("Authentication Not Successful\n");
                 printf("\n");
            }

        }

            }
    else
    {
        printf("\n");
        printf("Invalid User Input\n");
        continue;
    }
    }
free(users);
return 0;
}
