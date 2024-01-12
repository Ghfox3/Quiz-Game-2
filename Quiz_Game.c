#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void questionss();
void rules();
void scores();

/*============================================= MENU =============================================*/
int main(void)
{
    int menu;
    printf("=====>[ MENU ]<=====\n");
    printf("1. Play\n");
    printf("2. Scores\n");
    printf("3. Rules\n");
    printf("4. Exit\n");
    printf(">> ");
    scanf("%d", &menu);

    switch(menu) 
    {
        case 1:
            puts("");
            questionss();
            break;
        case 2:
            puts("");
            scores();
            break;
        case 3:
            puts("");
            rules();
            break;
        case 4:
            puts("");
            exit(1);
            break;
        default:
            puts("INVALID INPUT!");
            main();
            break;
    }
}

/*============================================= QUESTIONS =============================================*/
char questions[][100] = { "What is the hottest planet in the Solar System?",
    "In which country is the Leaning Tower of Pisa located?",
    "What is the largest living mammal?",
    "Who was a disciple of Socrates?",
    "What is the name of the largest ocean the world?",
    "What is the name of the smallest country in the world?",
    "How many contenents are there in the World?",
    "How many time zones does Russia have?",
    "Where does Spanish Steps located?",
    "What season does Australia experience in December?",
    "What is the largest desert in the world?",
    "Where is Red Square located?",
    "Where is Burj Khalifa located?",
    "Which country is famous with The Wailing Wall?",
    "What is the national sport of Canada?",
    "How many medals did China win at the Beijing Olympics?",
    "How many holes are played in an average round of golf?",
    "How many players in a regular Basketball team?",
    "Which of the following sports does not use a ball?",
    "What was the fastest goal in World Cup history?",
    "Where did the first Ancient Olympic Games take place?",
    "How many rings are there on the Olympic flag?",
    "Which country has won the most FIFA World Cup titles?",
    "Who won the last Champions League final in football?",
    "How did Spider-Man get his powers?",
    "In The Matrix, which was the color of the pill that Neo take?",
    "How many suns does Luke's home planet of Tatooine have in Star Wars?",
    "How many Oscar Award that Tom Hanks have?",
    "Who directed the 1994 film Pulp Fiction?",
    "What gift does Rose find in her coat pocket at the end of Titanic?",
    "What kind of breakfast does Donkey want to make with Shrek in Shrek?",
    "In Inception, how many dream levels does the crew enter?",
    "What did Zach Galifianakis call the baby in The Hangover?"};

char options[][100] = { "A)Venus", "B)Neptune", "C)Mars", "D)Mercury",
    "A)Egypt", "B)Mexico", "C)Italy", "D)China",
    "A)Killer Whale", "B)Elephant", "C)Blue Whale", "D)Giraffe",
    "A)Democritus", "B)Platon", "C)Aristotales", "D)Diogenes",
    "A)Pacific Ocean", "B)Atlantic Ocean", "C)Indian Ocean", "D)Arctic Ocean",
    "A)Finland", "B)Japan", "C)Vatican City", "D)Liechtenstein",
    "A)4", "B)5", "C)6", "D)7",
    "A)10", "B)11", "C)14", "D)15",
    "A)Rio de Janerio, Brazil", "B)Zaragoza,Spain", "C)Munih,Germany", "D)Rome,Italy",
    "A)Spring", "B)Summer", "C)Autumn", "D)winter",
    "A)Sahara", "B)Atacama", "C)Victoria", "D)Sonoran",
    "A)China", "B)Japan", "C)Russia", "D)Kazakhistan",
    "A)Saudi Arabia", "B)United Arab Emirates", "C)Qatar", "D)Egypt",
    "A)Israel", "B)Iran", "C)Pakistan", "D)Afghanistan",
    "A)Soccer", "B)Baseball", "C)Lacroose", "D)Tennis",
    "A)10", "B)50", "C)80", "D)100",
    "A)16", "B)18", "C)20", "D)22",
    "A)5", "B)6", "C)7", "D)8",
    "A)Golf", "B)Tennis", "C)Hockey", "D)Polo",
    "A)5 seconds", "B)10 seconds", "C)30 seconds", "D)1 minute",
    "A)Italy", "B)Egypt", "C)Finland", "D)Greece",
    "A)4", "B)5", "C)6", "D)7",
    "A)Italy", "B)France", "C)Germany", "D)Brazil",
    "A)Atletico Madrid", "B)Bayern Munich", "C)Manchester City FC", "D)Milan",
    "A)bitten by a radioactvie spider", "B)born with them", "C)woke up with them after a strange dream", "D)because of an experiment",
    "A)Yellow", "B)Blue", "C)Red", "D)Black",
    "A)0", "B)2", "C)4", "D)6",
    "A)0", "B)1", "C)2", "D)3",
    "A)Steven Spielberg", "B)Stanley Cubrick", "C)David Lean", "D)Quentin Tarantino",
    "A)A necklace", "B)A bracelet", "C)A flower", "D)A Picture of her",
    "A)Scrambled eggs", "B)French fries", "C)Waffles", "D)Straw",
    "A)5000", "B)500", "C)50", "D)5",
    "A)Carlos", "B)Jeffrey", "C)Samuel", "D)Johnson"};

char answers[33] = {'A', 'C', 'C', 'B', 'A', 'C', 'D','B','D','A','A','C','B','A','C','D','B','A','C','B','D','A','D','C','A','C','B','C','D','A','C','D','A'};
int number_of_questions = sizeof(questions) / sizeof(questions[0]);
int number_of_questions_to_ask = 5;

char guess;
int score = 0;

int score_data[20] = {0};
int play = 0;

char quit;

void questionss()
{
    srand(time(NULL));

    for(int i = 0; i < number_of_questions_to_ask; i++)
    {
        int random_question;
        int used_questions[5] = {0};
        
        do{
            random_question = rand() % number_of_questions;
        } while (used_questions[random_question] == 1); 

        used_questions[random_question] = 1;

        printf("#===========================================================#\n");
        printf("%d) %s\n", i + 1, questions[random_question]);

        for(int j = (random_question * 4); j < (random_question * 4) + 4; j++)
            printf("%s\n", options[j]);

        printf("Guess: ");
        scanf("%c", &guess);
        scanf("%c");

        guess = toupper(guess);

        if(guess == answers[random_question])
        {
            printf("CORRECT!\n");
            score = score + (100 / number_of_questions_to_ask);
        }
        else
        {
            printf("WRONG! Correct answer is: %c\n", answers[random_question]);
        }
    }

    score_data[play] = score;
    play = play + 1;

    printf("#===========#\n");
    printf("Score: %d\n", score);
    printf("#===========#\n");
    puts("");

    score = 0;

    main();
}

/*============================================= RULES =============================================*/
void rules()
{
    printf("=====>[ RULES ]<=====\n");
    printf("1- Do not enter option other than the options given in the main menu.\n");
    printf("2- In the questions, you should only write the available options as guesses(A,a,B,b,C,c,D,d). Otherwise, your guess will be wrong.\n");
    printf("3- Enter 'q' to return to the menu.\n");
    printf(">> ");
    scanf("%c", &quit);
    scanf("%c");

    if(quit == 'q')
    {
        puts("");
        main();
    }
    else
    {
        puts("INVALID INPUT!");
        rules();
    }
}

/*============================================= SCORES =============================================*/
void scores()
{   
    printf("=====>[ SCORES ]<=====\n");

    for(int i = 0; i < play; i++)
        printf("Trial %d: %d\n", i + 1, score_data[i]);

    printf(">> ");
    scanf("%c", &quit);
    scanf("%c");

    if(quit == 'q')
    {
        puts("");
        main();
    }
    else
    {
        puts("INVALID INPUT!");
        scores();
    }
}