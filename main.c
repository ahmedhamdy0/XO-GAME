#define BOARD_WEDITH 3
#define BOARD_HEIGHT 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//===============================[ Global Variables     ]================================
char board[BOARD_WEDITH][BOARD_HEIGHT] = {{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}};
char game_mode ;
char player ;    	  				// x or o
char computer ;       				// x or o
char player_position = -1 ;
char computer_position  = -1 ;
char option ;
char flag  = 1 ;				    //  1 = player turn  , 0 = computer turn
int temp_index = 0 ;
char temp[10] = { ' ' , ' ' , ' ' ,
		' ' , ' ' , ' ' ,
		' ' , ' ' , ' '} ;

int winner ;
//================================[ Functions Prototypes ]==============================
void ConfigGame( void ) ;
void MultiPlayerMode( void ) ;
void SinglePlayerMode( void ) ;
int WhoWin( void ) ;
void Delay( unsigned char ) ;
void ClearBoard( void ) ;
void Exit( void ) ;
void DisplayOptions( void ) ;
void DisplayTemp( void ) ;
char ComputerMove( void ) ;
char IsValid(char) ;
//----------------------------------------------------------------------
int main()
{
	ConfigGame() ;
	do{
		if(game_mode == 'm')
		{
			while(1==1)
			{
				MultiPlayerMode();
				winner = WhoWin() ;

				if( winner==1 )
				{
					fflush(stdout);
					system("CLS") ;
					printf("\n\n\n\n\n\t\t\t\t\t===============================================") ;
					printf("\n\n\n\n\n\t\t\t\t\t\tPlayer [ X ] Wins , Congratulations !\n") ;
					printf("\n\n\n\n\n\t\t\t\t\t===============================================") ;
					Delay(1) ;
					ClearBoard() ;
					break ;
				}
				else if( winner==0 )
				{
					fflush(stdout);
					system("CLS") ;
					printf("\n\n\n\n\n\t\t\t\t\t==============================================") ;
					printf("\n\n\n\n\n\t\t\t\t\t\t\t\tPlayer [ O ] Wins , Congratulations !\n");
					printf("\n\n\n\n\n\t\t\t\t\t==============================================") ;
					Delay(1) ;
					ClearBoard() ;
					break ;
				}
				else if( winner==5 )
				{
					fflush(stdout);
					system("CLS") ;
					printf("\n\n\n\n\n\t\t\t\t\t=============================================") ;
					printf("\n\n\n\n\n\t\t\t\t\t\t\t\tNo One Wins \n") ;
					printf("\n\n\n\n\n\t\t\t\t\t=============================================") ;
					Delay(1) ;
					ClearBoard() ;
					break ;
				}

			}
		}
		//===========================[ single mode ]=======================================
		else if( game_mode == 's')
		{
			while(1==1)
			{
				SinglePlayerMode() ;
				int winner = WhoWin() ;
				if( winner==1 )
				{
					fflush(stdout);
					system("CLS") ;
					printf("\n\n\n\n\n\t\t\t\t\t===============================================") ;
					printf("\n\n\n\n\n\t\t\t\t\t\tPlayer [ X ] Wins , Congratulations !\n") ;
					printf("\n\n\n\n\n\t\t\t\t\t===============================================") ;
					Delay(1) ;
					ClearBoard() ;
					break ;
				}
				else if( winner==0 )
				{
					fflush(stdout);
					system("CLS") ;
					printf("\n\n\n\n\n\t\t\t\t\t==============================================") ;
					printf("\n\n\n\n\n\t\t\t\t\t\t\t\tPlayer [ O ] Wins , Congratulations !\n");
					printf("\n\n\n\n\n\t\t\t\t\t==============================================") ;
					Delay(1) ;
					ClearBoard() ;
					break ;
				}
				else if( winner==5 )
				{
					fflush(stdout);
					system("CLS") ;
					printf("\n\n\n\n\n\t\t\t\t\t=============================================") ;
					printf("\n\n\n\n\n\t\t\t\t\t\t\t\tNo One Wins \n") ;
					printf("\n\n\n\n\n\t\t\t\t\t=============================================") ;
					Delay(1) ;
					ClearBoard() ;
					break ;
				}

			}
		}

		while(1==1)
		{
			DisplayOptions();
			if(option == 'y')
			{
				ConfigGame() ;
				break ;
			}
			else if(option == 'n')
			{
				Exit() ;
			}
		}
	}while(option=='y');
	return 0 ;
}
//----------------------------------------------------------------------
void ConfigGame( void )
{
	ClearBoard() ;
	do{
		system("CLS");
		fflush(stdout);
		printf("\n\n");
		printf("\t\t\t==============================\n") ;
		printf("\t\t\t===| Welcome To X-O Game |====\n") ;
		printf("\t\t\t==============================") ;
		printf("\n\n");
		printf("\n\n\n\n\n");
		printf("\t\t\t( * ) Enter [ s ] For Single Player Mode\n") ;
		printf("\t\t\t( * ) Enter [ m ] For Multi Player Mode\n") ;
		printf("\t\t\t------------------------------------------\n") ;

		printf("\t\t\tGame Mode : ") ;
		fflush(stdin);
		scanf("%c" , &game_mode) ; // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

	}while(game_mode !='s' && game_mode!='m');

	do{
		system("CLS") ;
		fflush(stdout);
		printf("\n\n");
		printf("\t\t\t==============================\n") ;
		printf("\t\t\t===| Welcome To X-O Game |====\n") ;
		printf("\t\t\t==============================\n") ;

		printf("\n\n");
		printf("\n\n\n\n\n");
		printf("\t\t\t( * ) Enter [ x ] To Play with X\n") ;
		printf("\t\t\t( * ) Enter [ o ] To Play with O\n") ;
		printf("\t\t\t------------------------------------------\n") ;
		printf("\t\t\tI Will Play With :  ") ;
		fflush(stdin);
		scanf("%c" , &player) ;

	}while(player !='x' && player !='o') ;
}
//----------------------------------------------------------------------
void MultiPlayerMode( void )
{
	system("CLS") ;
	fflush(stdout);
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t==============================================\n") ;
	printf("\t\t\t===========| Welcome To X-O Game |============\n") ;
	printf("\t\t\t==============================================\n") ;
	printf("\t\t\tEnter ( q ) To Close the Game at any time\n") ;
	printf("\t\t\t----------------------------------------------");
	printf("\n\n\n");

	for(int row=0 ; row<3 ; row++ )
	{
		printf("\t\t\t    ");
		for(int col=0 ; col<3 ; col++)
		{
			fflush(stdout);
			printf(" : %c : " , board[row][col]) ;
		}
		fflush(stdout);
		printf("\n\t\t\t    .....................\n");
	}
	fflush(stdout);
	printf("\n\n");
	do{
		printf("Enter Cell Number For Player [ %c ] : " , player) ;
		fflush(stdin);
		scanf("%c", &player_position);
		if(player_position == 'q')
		{
			Exit();
		}
		Delay(1);
	}while(!IsValid(player_position));

	system("CLS") ;
	fflush(stdout);
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t==============================\n") ;
	printf("\t\t\t===| Welcome To X-O Game |====\n") ;
	printf("\t\t\t==============================") ;
	printf("\n\n\n\n\n\n\n\n\n");

	if(player_position== 'q')
	{
		Exit() ;
	}
	for( int row = 0  ; row<3 ; row++ )
	{
		for(int col = 0 ; col<3 ; col++)
		{
			if((board[row][col]) == player_position )
			{
				board[row][col] = player ;
			}
			fflush(stdout);
			printf("\t\t%c\t" , board[row][col]) ;
		}
		fflush(stdout);
		printf("\n\n\n\n") ;
	}

	if(player == 'x')
	{
		player = 'o' ;
	}
	else
	{
		player = 'x' ;
	}
}
//----------------------------------------------------------------------
void Delay( unsigned char sec )
{
	unsigned int ms = sec*1000 ;
	unsigned int start_time = clock() ;
	while(clock() < start_time + ms ) ;
}
//----------------------------------------------------------------------
void ClearBoard(void)
{
	fflush(stdin) ;
	fflush(stdout) ;

	flag = 1 ;
	game_mode = ' ';
	player = ' ' ;
	computer = ' ' ;
	player_position = -1 ;
	computer_position = -1 ;

	board[0][0] = '1' ;
	board[0][1] = '2' ;
	board[0][2] = '3' ;

	board[1][0] = '4' ;
	board[1][1] = '5' ;
	board[1][2] = '6' ;

	board[2][0] = '7' ;
	board[2][1] = '8' ;
	board[2][2] = '9' ;
	temp_index = 0 ;
	for(int index = 0 ; index<10 ; index++ )
	{
		temp[index]= ' ' ;
	}
}
//----------------------------------------------------------------------
void Exit( void )
{
	system("CLS") ;
	fflush(stdout);
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\tNice Game Hope To See You Later : )") ;
	Delay(1) ;
	exit(0) ;
}
//----------------------------------------------------------------------
int WhoWin( void )
{
	unsigned char x_counter = 0 ;
	unsigned char o_counter = 0 ;
	unsigned char indication_flag = 0 ;

	// Check Rows =====================================
	for(int row = 0 ; row<3 ; row++)
	{
		for(int col = 0 ; col<3; col++)
		{
			if(board[row][col] !='x' && board[row][col] !='o')
			{
				indication_flag++ ; // if 0 = no available places
			}
			if(board[row][col] == 'x')
			{
				x_counter++ ;      // count X
			}
			else if(board[row][col] == 'o')
			{
				o_counter++ ;       // count O
			}

			if(x_counter==3 || o_counter==3)
			{
				return x_counter>o_counter?1:0 ; // 1 = x win , 0 = o win
			}
		}
		x_counter = 0 ;
		o_counter = 0 ;
	}

	// Check Columns =========================
	for(int row = 0 ; row<3 ; row++)
	{
		for(int col = 0 ; col<3; col++)
		{
			if(board[col][row] == 'x')
			{
				x_counter++ ;
			}
			else if(board[col][row] == 'o')
			{
				o_counter++ ;
			}
			if(x_counter==3 || o_counter==3)
			{
				return x_counter>o_counter?1:0 ;
			}
		}
		x_counter = 0 ;
		o_counter = 0 ;
	}

	// Check Diagonals
	if(board[0][0]=='x' && board[1][1]=='x' && board[2][2]=='x')
	{
		return 1  ;
	}

	else if(board[0][0]=='o' && board[1][1]=='o' && board[2][2]=='o')
	{
		return 0  ;
	}


	if (board[0][2]=='x' && board[1][1]=='x' && board[2][0]=='x')
	{
		return 1  ;
	}

	else if(board[0][2]=='o' && board[1][1]=='o' && board[2][0]=='o')
	{
		return 0  ;
	}

	if(indication_flag == 0 ) // no places available
	{
		return 5 ; // no one wins
	}
	return -1 ; // still playing
}

//----------------------------------------------------------------------
void DisplayOptions( void )
{
	system("CLS") ;
	fflush(stdout);
	printf("\n\n\n\n\n\t\t\t\t\t===============================================\n") ;
	printf("\t\t\t\t\t\t( * ) - Enter [ y ] to Play Again  \n") ;
	printf("\t\t\t\t\t\t( * ) - Enter [ n ] to Exit       \n") ;
	printf("\t\t\t\t\t================================================\n");
	printf("\n\n\t\t\t\t\t> > > : ") ;
	fflush(stdin);
	scanf("%c" , &option) ;
}

//----------------------------------------------------------------------
void SinglePlayerMode( void )
{
	system("CLS") ;
	fflush(stdout);
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t==============================================\n") ;
	printf("\t\t\t===========| Welcome To X-O Game |============\n") ;
	printf("\t\t\t==============================================\n") ;
	printf("\t\t\tEnter ( q ) To Close the Game at any time\n") ;
	printf("\t\t\t----------------------------------------------");
	printf("\n\n\n");

	if(flag == 1 ) // player turn
	{
		for(int row=0 ; row<3 ; row++ )
		{
			fflush(stdout);
			printf("\t\t\t    ");
			for(int col=0 ; col<3 ; col++)
			{
				fflush(stdout);
				printf(" : %c : " , board[row][col]) ;
			}
			fflush(stdout);
			printf("\n\t\t\t    .....................\n");

		}

		fflush(stdout);
		printf("\n\n");

		DisplayTemp();

		do{
			printf("\t\t\tEnter Cell Number For Player [ %c ] : " , player) ;
			fflush(stdin);
			scanf("%c", &player_position);
			if(player_position == 'q')
			{
				Exit();
			}
			Delay(1);
		}while(!IsValid(player_position));
		//................................................
		temp[temp_index] = player_position ;//<<<<<<
		temp_index++ ;
		system("CLS") ;
		fflush(stdout);
		printf("\n\n\n\n\n\n\n\n\n");
		printf("\t\t\t==============================\n") ;
		printf("\t\t\t===| Welcome To X-O Game |====\n") ;
		printf("\t\t\t==============================") ;
		printf("\n\n\n\n\n\n\n\n\n");

		if(player_position== 'q')
		{
			Exit() ;
		}

		for( int row = 0  ; row<3 ; row++ )
		{
			for(int col = 0 ; col<3 ; col++)
			{
				if((board[row][col]) == player_position )
				{
					board[row][col] = player ;
				}
				printf("\t\t%c\t" , board[row][col]) ;
			}
			fflush(stdout);
			printf("\n\n\n\n") ;
		}

		if(player == 'x')
		{
			computer = 'o' ;
		}
		else
		{
			computer = 'x' ;
		}

		flag = 0 ;
	}

	else if(flag == 0 )// computer turn
	{
		computer_position = ComputerMove() ;
		do{
			computer_position = ComputerMove() ;
		}while(computer_position == player_position );

		for( int row = 0  ; row<3 ; row++ )
		{
			fflush(stdout);
			printf("\t\t\t    ");
			for(int col = 0 ; col<3 ; col++)
			{
				if((board[row][col]) == computer_position )
				{
					board[row][col] = computer ;
				}
				fflush(stdout);
				printf(" : %c : " , board[row][col]) ;
			}
			fflush(stdout);
			printf("\n\t\t\t    .....................\n");
		}
		fflush(stdout);
		printf("Computer Played To [ %c ] " , computer_position ) ;
		temp[temp_index] = computer_position ;
		temp_index++ ;
		flag = 1 ;
	}// computer turn
}
//----------------------------------------------------------------------
void DisplayTemp( void ){
	fflush(stdout) ;
	printf("\t\t\t=============================================================================\n\t\t") ;
	for(int i = 0 ; i<10 ; i++)
	{
		printf("\t(%c) " , temp[i]) ;
	}
	printf("\n\t\t\t=============================================================================\n") ;
	printf("\n\n") ;
}
//-------------------------------------------------------------------------
char ComputerMove( void ){
	char position_played ;
	int found;

	srand(time(NULL));

	do {
		position_played = '0' + (rand()%(9-1+1)) + 1 ;
		found = 0;  // character not founded
		for (int i = 0; i < 5; i++)
		{
			if (temp[i] == position_played)
			{
				found = 1;
				break;
			}
			else
			{

			}
		}
	} while (found != 0); // while it is exist ( found = 1 )
	// while it is founded ( while flag = 1 )
	return position_played ;
}
//-----------------------------------------------------------------------------------
char IsValid(char position)
{
	switch(position){
	case '1' :
	case '2' :
	case '3' :
	case '4' :
	case '5' :
	case '6' :
	case '7' :
	case '8' :
	case '9' :
		return 1 ;
	default :
		return 0 ;
	}
}
