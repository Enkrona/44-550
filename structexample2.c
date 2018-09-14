//  This is telling the compiler to treat point3d as just a name point3d
//  Everything is public in the struct! 
typedef struct point3d
{

	double x,y,z;

} point3d;

int main (int argc, char* argv[])
{
	// Initalization lists to create the struct
	// we are initalizing the point with x = 1, y =2, z=2.1
	point3d pt = {1.0, 2.0, 2.1};
	
	return 0;


}
