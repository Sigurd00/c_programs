/*
*   Jacob Johannes Sigurd Skadborg
*   jskadb20@student.aau.dk
*   Gruppe A408a
*   Software
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUMBER_OF_TEAMS 14

enum team_names{FCM, EFB, SDR, RFC, ACH, FCN, LBK, AaB, OB, FCK, BIF, SIF, HOB, AGF};

typedef struct date{
    char weekday[4];
    int day;
    int month;
    double hour;
} date;

typedef struct game{
    date date;
    char team1[4];
    char team2[4];
    int goals_team1;
    int goals_team2;
    int spectators;
} game;

typedef struct team{
    char *teamname;
    int score;
    int goals;
    int goals_against;
} team;

game *get_tournament(char *filename);
game get_game(char* line);
team *generate_team_names();
char *team_name(int team);
team *calculate_team_scores(game *game, team *team, int count_games);
void print_team_scores(team *team);
int h(char *teamname);
int count_file_lines(char* filename);
void sort_teams_by_score_and_goals(team team[]);
int teams_cmp_by_score_and_goals(const void *p1, const void *p2);
int team_cmp_by_goals(int goals1, int goals2);
int team_cmp_by_score(int score1, int score2);

int main(void){
    int count_games = count_file_lines("kampe-2019-2020.txt");
    game *tournament = get_tournament("kampe-2019-2020.txt");
    team *teams = generate_team_names();
    teams = calculate_team_scores(tournament, teams, count_games);
    sort_teams_by_score_and_goals(teams);
    print_team_scores(teams);
    free(tournament); free(teams); 
    return EXIT_SUCCESS;
}

/*Dynamically creates structarray for the tournament*/
game *get_tournament(char *filename){
    int count_games = count_file_lines(filename);
    int i;
    char line[64];
    /*Explicit struct game type for malloc*/
    game *game = (struct game *) malloc(sizeof(struct game) * count_games);
    FILE *stream = fopen(filename, "r");

    for(i = 0; i < count_games; i++){
        fgets(line, 64, stream);
        game[i] = get_game(line);
    }
    fclose(stream);
    return game;
}

/* Constructs a game from the line read by file */
game get_game(char* line){
    game game;

    /* Scanset for line to correctly read the data */
    sscanf(line, " %s %d / %d %lf %s - %s %d - %d %d ",
        game.date.weekday, &game.date.day, &game.date.month, 
        &game.date.hour, game.team1, game.team2, &game.goals_team1,
        &game.goals_team2, &game.spectators);
    return game;
}

/* Generates team names */
team *generate_team_names(){
    int i;
    team *teams = (struct team *) malloc(sizeof(struct team) * NUMBER_OF_TEAMS);
    for(i = 0; i < NUMBER_OF_TEAMS; i++){
        teams[i].teamname = team_name(i);
        teams[i].goals = 0;
        teams[i].goals_against = 0;
        teams[i].score = 0;
    }
    return teams;
}

/*Helperfunction - Gets the team name string for every team */
char *team_name(int team){
    /* All teams are 3 letters plus '\n', whitespace for OB*/
    char *team_name = (char *) malloc(4 * sizeof(char));
    switch (team){
        case FCM: team_name = "FCM"; break;
        case EFB: team_name = "EFB"; break;
        case SDR: team_name = "SDR"; break;
        case RFC: team_name = "RFC"; break;
        case ACH: team_name = "ACH"; break;
        case FCN: team_name = "FCN"; break;
        case LBK: team_name = "LBK"; break;
        case AaB: team_name = "AaB"; break;
        case OB:  team_name = "OB "; break;
        case FCK: team_name = "FCK"; break;
        case BIF: team_name = "BIF"; break;
        case SIF: team_name = "SIF"; break;
        case HOB: team_name = "HOB"; break;
        case AGF: team_name = "AGF"; break;
        default: break;
    }
    return team_name;
}

/* Gives the correct scores to the correct teams for each game */
team *calculate_team_scores(game *game, team *team, int count_games){
    int i;
    int team1_i, team2_i; /* Index for teams */

    for(i = 0; i < count_games; i++){
        /* Saving the index here makes us able to only look onece per game, per team */
        team1_i = h(game[i].team1); team2_i = h(game[i].team2);
        
        team[team1_i].goals += game[i].goals_team1;
        team[team2_i].goals += game[i].goals_team2;
        team[team1_i].goals_against += game[i].goals_team2;
        team[team2_i].goals_against += game[i].goals_team1;
        if(game[i].goals_team1 > game[i].goals_team2)
            team[team1_i].score += 3;
        else if(game[i].goals_team1 < game[i].goals_team2)
            team[team2_i].score += 3;
        else{
            team[team1_i].score++;
            team[team2_i].score++;
        }
    }
    return team;
}

/* Sorts teams by score and goals using qsort, uses cmp functions */
void sort_teams_by_score_and_goals(team team[]){
    qsort(team, NUMBER_OF_TEAMS, sizeof(struct team), teams_cmp_by_score_and_goals);
}

/* Compares two teams by score and goals */
int teams_cmp_by_score_and_goals(const void *p1, const void *p2){
    const team *team1 = (const team *)p1; 
    const team *team2 = (const team *)p2;
    
    if(team1->score == team2->score)
        return team_cmp_by_goals(team1->goals, team2->goals);
    else return team_cmp_by_score(team1->score, team2->score);
}

/* Compares goals */
int team_cmp_by_goals(int goals1, int goals2){
    return (goals1 < goals2) - (goals1 > goals2);
}

/* Compares teams */
int team_cmp_by_score(int score1, int score2){
    return (score1 < score2) - (score1 > score2);
}

/* Prints the team scores */
void print_team_scores(team *team){
    int i;
    printf("This is the scoreboard!\n\n");
    for(i = 0; i < NUMBER_OF_TEAMS; i++){
        printf("%s Score:%3d Goals:%3d Goals Against:%3d\n", 
            team[i].teamname, team[i].score, team[i].goals, team[i].goals_against);
    }
}

/* Helperfunction - Returns the index position of a team depending on name */
int h(char *teamname){
    if(strcmp(teamname, "FCM") == 0)      return FCM;
    else if(strcmp(teamname, "EFB") == 0) return EFB;
    else if(strcmp(teamname, "SDR") == 0) return SDR;
    else if(strcmp(teamname, "RFC") == 0) return RFC;
    else if(strcmp(teamname, "ACH") == 0) return ACH;
    else if(strcmp(teamname, "FCN") == 0) return FCN;
    else if(strcmp(teamname, "LBK") == 0) return LBK;
    else if(strcmp(teamname, "AaB") == 0) return AaB;
    else if(strcmp(teamname, "OB")  == 0) return OB;
    else if(strcmp(teamname, "FCK") == 0) return FCK;
    else if(strcmp(teamname, "BIF") == 0) return BIF;
    else if(strcmp(teamname, "SIF") == 0) return SIF;
    else if(strcmp(teamname, "HOB") == 0) return HOB;
    else if(strcmp(teamname, "AGF") == 0) return AGF;
    else return -1;/* Should never happen, will result in seg.fault */
}

/*Helperfunction - Returns the number of lines in file*/
int count_file_lines(char* filename){
    char line[64];
    int count = 0;
    FILE *stream = fopen(filename, "r");
    /* fgets will set the file pointer to the next line after reading,
     * therefore this will give us the number of lines in file */
    while(fgets(line, 64, stream)){
        count++;
    }
    fclose(stream);
    return count;
}
