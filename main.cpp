#include <stdlib.h>	   // For malloc() etc.
#include <stdio.h>	   // For printf(),	fopen()	etc.
#include <math.h>	   // For sin(), cos() etc.
#include <GL/glfw.h>   // For GLFW,	OpenGL and GLU
#include <iostream>
#include <vector>
#include <string>
//#include <pair>
#include "mylib.h"

using namespace	std;

class word {
	wstring str;
	wstring input;
	public:
	word(wchar_t* ws)
		:str(ws)
	{
	}
	word(wstring ws)
		:str(ws)
	{
	}
	word()
	{
	}
	void add(wchar_t c)
	{
		input += c;
	}
	void print()
	{
		wcout << str << endl;
	}
	void printinput()
	{
		wcout << input << endl;
	}

};
/*class treenode {
	public:
		vector<pair < vector<wstring>*,treenode* > > children;
		//	vector<treenode*> child;
		//	vector<wstring> value;

		treenode()
		{

		}
		//	void push(treenode* node)
		//	{
		//		child.push_back(node);
		//	}
		//	void add(wstring wstr)
		//	void add(pair<vector<wstring>,treenode*> v)
		void add(vector<wstring>* vec,treenode* nodep)
		{
			children.push_back(pair<vector<wstring>*,treenode*>(vec,nodep));
		}
		void print()
		{
			for(vector<pair<vector<wstring>*,treenode*> >::iterator i = children.begin(); i != children.end();++i) {
				//if(*i == s) {return true;}
				wcout << (i->first->at(0)) << endl;
			}
		}

};
class treefactory {
	multimap<wstring,wstring> dic;
	public:
	treefactory(multimap<wstring,wstring> v)
	{dic = v;};
	treenode* maketree(wstring tstr)
	{
		treenode* temp = new treenode();

		//			vector<wstring> result;
		//
		wstring::iterator i = tstr.begin();
		do {
			std::pair<multimap<wstring,wstring>::iterator, std::multimap<wstring,wstring>::iterator> iterpair;
			multimap<wstring,wstring>::iterator j;
			iterpair = dic.equal_range(wstring(tstr.begin(),i));
			if(iterpair.first==iterpair.second) break;//(*temp).push(maketree(wstring(i,tstr.end())));
			vector<wstring>* tempvector = new vector<wstring>;

			for(j = iterpair.first;j!=iterpair.second;j++) {
				(*tempvector).push_back((*j).second);
				//(*temp).add((*j).second);
			}
			(*temp).add(tempvector,maketree(wstring(i,tstr.end())));
		} while(i++!=tstr.end());
		return temp;
	}
};
*/
word tanuki(wstring(L"ほげほげほげら"));
//const wstring word(L"ふぁいなるふぁんたじー");
//vector<wstring> a ;
bool flag =	false;
//wstring	wstr;
//vector<wstring>	vec;
//GLuint tex;// = 1;
double date = 0.0;
enum mode {
	MODE_TITLE,
	MODE_LOGO,
	MODE_GAME
};
//========================================================================
// Textures
//========================================================================

#define TEX_TITLE    0
#define TEX_MENU     1
#define TEX_INSTR    2
#define TEX_WINNER1  3
#define TEX_WINNER2  4
#define TEX_FIELD    5
//#define NUM_TEXTURES 6
#define NUM_TEXTURES 1

// Texture names
const char * tex_name[ NUM_TEXTURES ] = {
	//    "pong3d_title.tga",
	"sofmelogo.tga",
	//    "pong3d_menu.tga",
	//    "pong3d_instr.tga",
	//    "pong3d_winner1.tga",
	//    "pong3d_winner2.tga",
	//    "pong3d_field.tga"
};

// OpenGL texture object IDs
GLuint tex_id[ NUM_TEXTURES ];


void LoadTextures( void );
//class	letter {
//	wchar_t	c;
//	double birth;
//	letter(c)
//		c(L'b')
//	{birth = }
//};
//bool match(vector<wstring> v, wstring s)
//{
//	for(vector<wstring>::iterator i	= v.begin(); i != v.end();++i) {
//		if(*i == s)	{return	true;}
//	}
//	return false;
//}
//void settime() {if(match(vec,wstr)) {date = glfwGetTime();wstr.clear();}}
/*void print()
{
	wcout << glfwGetTime()-date << L'(' << (int)wstr.size() << L')'<< L": " <<  wstr	<< endl;
	//		wcout << (wstr == word)	<< endl;
	wcout << (match(vec,wstr)?L"match":L"unmatch") << endl;
}

*/

void GLFWCALL charinput( int character,	int	action )
{
	if(action == GLFW_PRESS) 
	{
		tanuki.add((wchar_t)character);
		//wstr +=	(wchar_t)character;
		//		if(match(vec,wstr)) {date = glfwGetTime();}//?L"match":L"unmatch")
		tanuki.printinput();
//		settime();
	}
}

//----------------------------------------------------------------------
// Draw() -	Main OpenGL	drawing	function that is called	each frame
//----------------------------------------------------------------------

void Draw( void	)
{

	int	   width, height;  // Window dimensions
	double t;			   // Time (in seconds)

	//glEnable( GL_TEXTURE_2D );
/*	if(!flag &&	glfwGetKey(	GLFW_KEY_BACKSPACE ) ==	GLFW_PRESS)	{ 
		flag = true;
//		if(wstr.size())	wstr.resize(wstr.size()-1);
//		print();
		settime();
	}
	*/
//	if(glfwGetKey( GLFW_KEY_BACKSPACE )	== GLFW_RELEASE) { flag	= false	;/*wstr.resize(wstr.size()-2);*/}

	// Get current time
	t =	glfwGetTime();

	// Get window size
	glfwGetWindowSize( &width, &height );

	// Make	sure that height is	non-zero to	avoid division by zero
	height = height	< 1	? 1	: height;

	// Set viewport
	glViewport(	0, 0, width, height	);

	// Clear color and depht buffers
	//	glClearColor( 0.0f,	0.0f, 0.0f,	0.0f );
	glClearColor( 1.0f,	1.0f, 1.0f,	0.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// Set up projection matrix
	glMatrixMode( GL_PROJECTION	);	  // Select	projection matrix
	glLoadIdentity();				  // Start with	an identity	matrix
	gluPerspective(					  // Set perspective view
			65.0,						  // Field of view = 65	degrees
			(double)width/(double)height, // Window	aspect (assumes	square pixels)
			1.0,						  // Near Z	clipping plane
			100.0						  // Far Z clippling plane
		      );

	// Set up modelview	matrix
	glMatrixMode( GL_MODELVIEW );	  // Select	modelview matrix
	glLoadIdentity();				  // Start with	an identity	matrix
	gluLookAt(						  // Set camera	position and orientation
			0.0, 0.0, 10.0,				  // Camera	position (x,y,z)
			0.0, 0.0, 0.0,				  // View point	(x,y,z)
			0.0, 1.0, 0.0				  // Up-vector (x,y,z)
		 );

	// Here	is where actual	OpenGL rendering calls would begin...
/*	if(t < 6.0) glTranslated(.0,fabs(sin(6.28*t))/(t*t),-5/(t*t*t*t));

	glScalef(1.5f,1.5f,1.5f);
	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, tex_id[ TEX_TITLE ] );
	glBegin(GL_QUADS);
	glTexCoord2f( 0.0f, 1.0f );
	glVertex2d(-8.0,1.0);
	glTexCoord2f( 1.0f, 1.0f );
	glVertex2d(8.0,1.0);
	glTexCoord2f( 1.0f, 0.0f );
	glVertex2d(8.0,-1.0);
	glTexCoord2f( 0.0f, 0.0f );
	glVertex2d(-8.0,-1.0);
	glEnd();
	glDisable( GL_TEXTURE_2D );
	*/

}


//----------------------------------------------------------------------
// main() -	Program	entry point
//----------------------------------------------------------------------

int	main( int argc,	char **argv	)
{
	int	   ok;			   // Flag telling if the window was opened
	int	   running;		   // Flag telling if the program is running
	setlocale(LC_ALL, "");
	//const multimap<wstring,wstring>& hash = init("roma2hira.dat");
	/*
	   treefactory t(hash); 
	   */

	/*	test.add(L"ぬるぽ");
		test.add(L"ほげ");
		test.add(L"はげ");
		test.print();
		*/
	//	wcout << hash.size()<< endl;
	//	vec = kana2roma(hash,word);
	//treefactory factory(hash);
	//treenode* test = factory.maketree(word);
	//wcout << test->children << endl;
	//	test->print();
	//	word i;
	//tanuki.print();
	//	return 0;
	//	OutputVector(vec);
	//	wcout << vec.size() << endl;

	// Initialize GLFW
	glfwInit();

	// Open	window
	ok = glfwOpenWindow(
			640, 480,		   // Width	and	height of window
			8, 8, 8,		   // Number of	red, green,	and	blue bits for color	buffer
			8,				   // Number of	bits for alpha buffer
			24,				   // Number of	bits for depth buffer (Z-buffer)
			0,				   // Number of	bits for stencil buffer
			GLFW_WINDOW		   // We want a	desktop	window (could be GLFW_FULLSCREEN)
			);

	// If we could not open	a window, exit now
	if(	!ok	)
	{
		glfwTerminate();
		return 0;
	}

	// Set window title
	glfwSetWindowTitle("My OpenGL program");

	glfwSetCharCallback(charinput);

	// Enable sticky keys
	glfwEnable(GLFW_STICKY_KEYS);

	//	tex = glfwLoadTexture2D("pong3d_title.tga",GLFW_BUILD_MIPMAPS_BIT);
	//	glGenTextures(1,&tex);
	//		glBindTexture( GL_TEXTURE_2D, tex );

	// Set texture parameters
	//      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	//      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	//      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	//      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

	// Upload texture from file to texture memory
	//     glfwLoadTexture2D( "pong3d_title.tga", 0 );
	//
//	LoadTextures();
	// Main	rendering loop
	do
	{
		// Call	our	rendering function
		Draw();

		// Swap	front and back buffers (we use a double	buffered display)
		glfwSwapBuffers();

		// Check if	the	escape key was pressed,	or if the window was closed
		running	= !glfwGetKey( GLFW_KEY_ESC	) &&
			glfwGetWindowParam( GLFW_OPENED );
	}
	while( running );

	// Terminate GLFW
	glfwTerminate();

	// Exit	program
	return 0;
}

void LoadTextures( void )
{
	int  i;

	// Generate texture objects
	glGenTextures( NUM_TEXTURES, tex_id );

	// Load textures
	for( i = 0; i < NUM_TEXTURES; i ++ )
	{
		// Select texture object
		glBindTexture( GL_TEXTURE_2D, tex_id[ i ] );

		// Set texture parameters
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

		// Upload texture from file to texture memory
		glfwLoadTexture2D( tex_name[ i ], 0 );
	}
}

