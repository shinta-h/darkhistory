#include "mylib.h"
//#include <vector>
//#include <map>
//#include <string>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
//
//#include <FTGL/FTGLPolygonFont.h>
//#include <stdlib.h>    // For malloc() etc.
////#include <stdio.h>     // For printf(), fopen() etc.
//#include <math.h>      // For sin(), cos() etc.
#include <GL/glfw.h>   // For GLFW, OpenGL and GLU

#define FONT "/usr/share/fonts/WinFont/msgothic.ttc"
#define SIZE 1.0
#define DEPTH 0.5

using namespace std;
using namespace boost::algorithm;
//wstring wstr(L"24時間働けますが？\n何か？\nほげ\n\nあああ");
vector<vector<wstring> > table;
multimap<wstring,wstring> hash;
ifstream hoge("roma2hira.dat");
wstring str,wstr(L"つるぺたはにゃーん");
string mstr;

//----------------------------------------------------------------------
// Draw() - Main OpenGL drawing function that is called each frame
//----------------------------------------------------------------------

void Draw( FTFont* font)
{
	int    width, height;  // Window dimensions
	double t;              // Time (in seconds)

	//hoge >> wstr;

	// Get current time
	t = glfwGetTime();

	// Get window size
	glfwGetWindowSize( &width, &height );

	// Make sure that height is non-zero to avoid division by zero
	height = height < 1 ? 1 : height;

	// Set viewport
	glViewport( 0, 0, width, height );

	// Clear color and depht buffers
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// Set up projection matrix
	glMatrixMode( GL_PROJECTION );    // Select projection matrix
	glLoadIdentity();                 // Start with an identity matrix
	gluPerspective(                   // Set perspective view
			65.0,                         // Field of view = 65 degrees
			(double)width/(double)height, // Window aspect (assumes square pixels)
			1.0,                          // Near Z clipping plane
			100.0                         // Far Z clippling plane
		      );

	// Set up modelview matrix
	glMatrixMode( GL_MODELVIEW );     // Select modelview matrix
	glLoadIdentity();                 // Start with an identity matrix
	gluLookAt(                        // Set camera position and orientation
			0.0, 0.0, 10.0,               // Camera position (x,y,z)
			0.0, 0.0, 0.0,                // View point (x,y,z)
			0.0, 1.0, 0.0                 // Up-vector (x,y,z)
		 );

	// Here is where actual OpenGL rendering calls would begin...
	//  glPushMatrix();
	//font->Render(L"ぬるぽっぽ");
	glTranslatef(-8.0f, 5.0f, 0.0f);
	convertMultiByteToWideChar("人間って良いな\nところで俺のキンタマを見てくれ\nこいつをどう思う？", str);
	// RenderText(font, str);
	//RenderText(font, kana2roma(hash,wstr)[1]);
	RenderVector(font, kana2roma(hash,wstr));

	//RenderVector(font, table);
	//RenderMap(font, hash, wstr);

	//RenderText(font, table[0][0]);
	// glPopMatrix();
	//glTranslatef(.0f, -font->LineHeight(), .0f);
	//font->Render(L"ほげああん\nあんあん");
}


//----------------------------------------------------------------------
// main() - Program entry point
//----------------------------------------------------------------------

int main( int argc, char **argv )
{
	int    ok;             // Flag telling if the window was opened
	int    running;        // Flag telling if the program is running
	FTFont *font;
	// Initialize GLFW
	setlocale(LC_ALL, "");
	glfwInit();

	//	while(getline(hoge,mstr)) 
	//	{vector<wstring> v;convertMultiByteToWideChar(mstr.c_str(), str);trim(str);if(starts_with(str, "#")) continue; split(v, str, is_space());if(v.size() != 2) continue;table.push_back(v);};
	while(getline(hoge,mstr)) 
	{vector<wstring> v;convertMultiByteToWideChar(mstr.c_str(), str);trim(str);if(starts_with(str, "#")) continue; split(v, str, is_space());if(v.size() != 2) continue;/*table.push_back(v);*/hash.insert(pair<wstring,wstring>(v[1],v[0]));};
	//    for(vector<vector<wstring> >::iterator i = table.begin(); i != table.end(); i++) {
	//
	//    cout << (*i)[0] << ":" << (*i)[1] << endl;
	//}
	// Open window
	ok = glfwOpenWindow(
			640, 480,          // Width and height of window
			8, 8, 8,           // Number of red, green, and blue bits for color buffer
			8,                 // Number of bits for alpha buffer
			24,                // Number of bits for depth buffer (Z-buffer)
			0,                 // Number of bits for stencil buffer
			GLFW_WINDOW        // We want a desktop window (could be GLFW_FULLSCREEN)
			);

	// If we could not open a window, exit now
	if( !ok )
	{
		glfwTerminate();
		return 0;
	}

	// Set window title
	glfwSetWindowTitle( "My OpenGL program" );

	// Enable sticky keys
	glfwEnable( GLFW_STICKY_KEYS );

	font = new FTGLPolygonFont(FONT);
	if (font->Error()) exit(1);                        // can't open font file
	if (!font->FaceSize(SIZE)) exit(1);                // can't set font size
	if (!font->CharMap(ft_encoding_unicode)) exit(1);  // can't set charmap 
	vector<wstring> a = kana2roma(hash,wstr);
	wcout << a.size() << a[0];
	//font->Depth(DEPTH);    // for FTGLExtrdFont()
	// Main rendering loop
	do
	{
		// Call our rendering function
		Draw(font);

		// Swap front and back buffers (we use a double buffered display)
		glfwSwapBuffers();

		// Check if the escape key was pressed, or if the window was closed
		running = !glfwGetKey( GLFW_KEY_ESC ) &&
			glfwGetWindowParam( GLFW_OPENED );
	}
	while( running );

	// Terminate GLFW
	glfwTerminate();

	// Exit program
	return 0;
}
