#include "sdlUtilities.h"

#include "macros.h"

#include "scene.h"
#include "entity.h"
#include "mesh.h"
#include "texture.h"
#include "rasterizer.h"
#include "color.h"

int main(int argc, char** argv)
{
    bool isValid;
    SDL_Utilities render(isValid);
    if (!isValid)
        return EXIT_FAILURE;


    Scene scene;

    // Entity cube;
    // cube.mesh = Mesh::CreateCube();
    // //set transform
    // //cube.transformation 
    // cube.transformation *= Mat4::CreateTranslationMatrix(Vec3(-2.5, 0, 2));

    // Entity sphere;
    // sphere.mesh = Mesh::CreateSphere(10, 10);
    // sphere.transformation *= Mat4::CreateTranslationMatrix(Vec3(2.5, 0, 2));
    // //set transform

    // scene.entities.push_back(cube);
    // scene.entities.push_back(sphere);

    Entity triangle;
    //triangle.mesh = Mesh::CreateSphere(100, 100);
    //triangle.mesh = Mesh::CreateTriangle(Vec3(0,0,0), Vec3(0.2,0,0), Vec3(0,0.2,0));
    triangle.mesh = new Mesh;
    triangle.mesh->vertices.push_back(Vec3(0,0,0));
    triangle.mesh->vertices.push_back(Vec3(0.5,0,0));
    triangle.mesh->indices.push_back(1);
    triangle.mesh->indices.push_back(0);

    scene.entities.push_back(triangle);

    Texture target(windowWidth, windowHeight);

    bool bRun = true;
    while (bRun)
    {
        //triangle.transformation = triangle.transformation * Mat4::CreateTranslationMatrix(Vec3(10, 0, 0));
        //std::cout << triangle.transformation << std::endl;
        //inputs
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE :
                            bRun = false;
                            break;
                    }

                default:break;
            }
        }

        //rasterizer
        Rasterizer::RenderScene(&scene, &target);

        SDL_RenderClear(render.renderer);
        SDL_Utilities::textureToSDL(target, render.renderer);
        SDL_RenderPresent(render.renderer);
    }

    return EXIT_SUCCESS;
}
