#include <cassert>

#include "texture.h"

#include "color.h"

Texture::Texture(unsigned int width, unsigned int height) 
    : width(width),
      height(height),
      pixels(new Color[width * height]) //default constructor init pixels to black
{
    
}

Texture::~Texture()
{
    if (pixels != nullptr)
        delete pixels;
}

void Texture::SetPixelColor(unsigned int x, unsigned int y, Color c)
{
    if (x > 0 && x < width && y > 0 && y < height)
        pixels[x + y * width] = c;
}

Color Texture::GetPixelColor(unsigned int x, unsigned int y) const
{
    assert(0 <= x && x < width && 0 <= y && y < height);
    return pixels[x + y * width];   
}

void Texture::FillBlack()
{
    for (unsigned int i = 0; i < width * height; i++)
    {
        pixels[i].r = 0.f;
        pixels[i].g = 0.f;
        pixels[i].b = 0.f;
        pixels[i].a = 1.f;
    }
}
