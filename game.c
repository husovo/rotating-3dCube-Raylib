#include <raylib.h>
#include <math.h>
#define width 1600
#define height 1400

Vector3 rotate(Vector3 A, float angle){

    return (Vector3) { 
        A.x * cosf(angle) +A.z*sinf(angle),
        A.y,
        -A.x * sinf(angle) + A.z * cosf(angle)
    };
}
const float cubeCentre = 1.5f;
Vector3 center(Vector3 p)
{
    return (Vector3){
        p.x -cubeCentre, p.y - cubeCentre, p.z - cubeCentre
    };
}

int main()
{
    InitWindow(width,height,"3DCube");
    SetTargetFPS(60);
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 0.0f, 8.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    Vector3 A = {0.0f,0.0f,0.f};
    Vector3 E1 = {1.0f,0.0f,0.0f};
    Vector3 E2 = {0.0f,1.0f,0.0f};
    Vector3 E3 = {0.0f,0.0f,1.0f};
    float r = 2*cubeCentre;
    Vector3 c0 = A;
    Vector3 c1 = {A.x + r*E1.x, A.y + r*E1.y, A.z + r*E1.z};
    Vector3 c2 = {A.x + r*E2.x, A.y + r*E2.y, A.z + r*E2.z};
    Vector3 c3 = {A.x + r*E3.x, A.y + r*E3.y, A.z + r*E3.z};
    Vector3 c4 = {A.x + r*E1.x + r*E2.x, A.y + r*E1.y + r*E2.y, A.z + r*E1.z + r*E2.z};
    Vector3 c5 = {A.x + r*E1.x+ r*E3.x, A.y + r*E1.y + r*E3.y, A.z + r*E1.z+ r*E3.z};
    Vector3 c6 = {A.x + r*E2.x+ r*E3.x, A.y + r*E2.y + r*E3.y, A.z + r*E2.z+ r*E3.z};
    Vector3 c7 = {A.x + r*E1.x + r*E2.x+ r*E3.x, A.y + r*E1.y + r*E2.y+ r*E3.y, A.z + r*E1.z + r*E2.z+ r*E3.z};
    float lineWidth = 0.1f;
    
    float angle = 0.0f;
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera);
        //DrawGrid(10.0f,1.0f);
        
        //original points before being centered and rotated.
        // DrawSphere(c0,lineWidth,RED);
        // DrawSphere(c1,lineWidth,GRAY);
        // DrawSphere(c2,lineWidth,GREEN);
        // DrawSphere(c3,lineWidth,BLUE);
        // DrawSphere(c4,lineWidth,PINK);
        // DrawSphere(c5,lineWidth,YELLOW);
        // DrawSphere(c6,lineWidth,PURPLE);
        // DrawSphere(c7,lineWidth,ORANGE);


        DrawSphere(rotate(center(c0),angle),lineWidth,RED);
        DrawSphere(rotate(center(c1),angle),lineWidth,GRAY);
        DrawSphere(rotate(center(c2),angle),lineWidth,GREEN);
        DrawSphere(rotate(center(c3),angle),lineWidth,BLUE);
        DrawSphere(rotate(center(c4),angle),lineWidth,PINK);
        DrawSphere(rotate(center(c5),angle),lineWidth,YELLOW);
        DrawSphere(rotate(center(c6),angle),lineWidth,PURPLE);
        DrawSphere(rotate(center(c7),angle),lineWidth,ORANGE);
        
        
        DrawCylinderEx(rotate(center(c0),angle),rotate(center(c1),angle),lineWidth,lineWidth,2,BROWN);
        DrawCylinderEx(rotate(center(c0),angle),rotate(center(c2),angle),lineWidth,lineWidth,2,BROWN);
        DrawCylinderEx(rotate(center(c0),angle),rotate(center(c3),angle),lineWidth,lineWidth,2,BROWN);
        DrawCylinderEx(rotate(center(c1),angle),rotate(center(c4),angle),lineWidth,lineWidth,2,BROWN);

        DrawCylinderEx(rotate(center(c2),angle),rotate(center(c4),angle),lineWidth,lineWidth,2,GREEN);
        DrawCylinderEx(rotate(center(c2),angle),rotate(center(c6),angle),lineWidth,lineWidth,2,GREEN);
        DrawCylinderEx(rotate(center(c3),angle),rotate(center(c5),angle),lineWidth,lineWidth,2,BLUE);
        DrawCylinderEx(rotate(center(c3),angle),rotate(center(c6),angle),lineWidth,lineWidth,2,BLUE);

        DrawCylinderEx(rotate(center(c4),angle),rotate(center(c7),angle),lineWidth,lineWidth,2,YELLOW);
        DrawCylinderEx(rotate(center(c5),angle),rotate(center(c1),angle),lineWidth,lineWidth,2,ORANGE);
        DrawCylinderEx(rotate(center(c5),angle),rotate(center(c7),angle),lineWidth,lineWidth,2,ORANGE);
        DrawCylinderEx(rotate(center(c6),angle),rotate(center(c7),angle),lineWidth,lineWidth,2,RED);

        if(IsKeyDown(KEY_DOWN))
        {
            camera.target.y+=0.1;
        }
        else if(IsKeyDown(KEY_UP))
        {
            camera.target.y-=0.1;
        }
        else if(IsKeyDown(KEY_RIGHT))
        {
            camera.target.x+=0.1;
        }
        else if(IsKeyDown(KEY_LEFT))
        {
            camera.target.x-=0.1;
        }
        

        angle += 0.01f;
        EndMode3D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}