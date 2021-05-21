#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <set>

using namespace std;

int main(){

	string ans;
	set<int> ansS;
	srand( time(NULL) );
	for( int i = 0; i < 4; ++i ){
		int k = 0;
		while( k == 0 ){
			int x = rand()%10;
			if( ansS.count( x ) )
				continue;
			else{
				k = 1;
				ansS.insert( x );
				ans.push_back( x+'0' );
			}
		}
	}

	string cur;
	int ctr = 0;
	string s[100];
	string status[100];

	puts( "Please enter four non-repetitive numbers: " );
	while( cin >> cur ){
		
		if( cur == "answer" ){
			cout << ans;
			puts( " is the answer." );
			system( "pause" );
			return 0;
		}

		if( cur.size() != 4 ){
			puts( "Invalid Input!!\n" );
			puts( "Please enter four non-repetitive numbers: " );
			continue;
		}
		
		set<char> check;
		int c = 0;
		for( int i = 0; i < 4; ++i ){
			if( !isdigit( cur[i] ) ){
				c = 1;
				break;
			}
			else if( check.count( cur[i] ) ){
				c = 1;
				break;
			}
			else
				check.insert( cur[i] );
		}
		if( c == 1 ){
			puts( "Invalid Input!!\n" );
			puts( "Please enter four non-repetitive numbers: " );
			continue;
		}
		
		s[ctr++] = cur;
		int a = 0, b = 0;
		for( int i = 0; i < 4; ++i ){
			for( int j = 0; j < 4; ++j ){
				if( cur[j] == ans[i] && j == i )
					++a;
				else if( cur[j] == ans[i] && !(j==i) )
					++b;
			}
		}
		
		string sta;
		sta.push_back( a+'0' );
		sta.push_back( 'A' );
		sta.push_back( b+'0' );
		sta.push_back( 'B' );
		status[ctr-1] = sta;

		if( a == 4 ){
			puts( "Congratulations!!" );
			cout << cur;
			puts( " is the right answer!!" );
			printf( "You tried %d times to get the right answer.\n", ctr );
			system( "pause" );
			return 0;
		}
		else{
			puts( "Sadly, this is a wrong answer!! Please try again!!\n" );
			puts( "----------------------" );
			puts( "| Times Input Status |" );
			puts( "----------------------" );
			for( int i = 0; i < ctr; ++i ){
				cout << "| ";
				switch( i%10 ){
					case 0: printf( "%2dst   ", i+1 ); break;
					case 1: printf( "%2dnd   ", i+1 ); break;
					case 2: printf( "%2drd   ", i+1 ); break;
					default: printf( "%2dth   ", i+1 ); break;
				} 
				cout << s[i] << "   " << status[i] << " |" << endl;
				puts( "----------------------" );
			}
			puts( "\nPlease enter four non-repetitive numbers: " );
		}
	}
}
