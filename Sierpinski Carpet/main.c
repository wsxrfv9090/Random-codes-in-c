/*
Decides if a point at a specific location is filled or not.
@param x is the x coordinate of the point being checked
@param y is the y coordinate of the point being checked
@param width is the width of the Sierpinski Carpet being checked
@param height is the height of the Sierpinski Carpet being checked
@return 1 if it is to be filled or 0 if it is not
*/
int isSierpinskiCarpetPixelFilled(int x, int y, int width, int height) {
    // base case
    if (x < 1) {
        return 0;
    }
    // general case
    else {
        /*
        If the grid was split in 9 parts, what part(x2,y2) would x,y fit into?
        */
        int x2 = x * 3 / width; // an integer from 0..2 inclusive
        int y2 = y * 3 / height; // an integer from 0..2 inclusive
        if (x2 == 1 && y2 == 1) // if in the centre squaure, it should be filled.
            return 1;
        /* offset x and y so it becomes bounded by 0..width/3 and 0..height/3
        and prepares for recursive call
        */
        x -= x2 * width / 3;
        y -= y2 * height / 3;
    }
    return isSierpinskiCarpetPixelFilled(x, y, width / 3, height / 3);
}

int main()
{
    int 
}