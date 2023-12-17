//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: directionalLight.cpp
// 
// Author: Frank Luna (C) All Rights Reserved
//
// System: AMD Athlon 1800+ XP, 512 DDR, GeForce 3, Windows XP, MSVC++ 7.0 
//
// Desc: Demonstrates using a directional light with D3DX objects.  You can orbit
//       the scene using the left and right arrow keys.  In addition you can 
//       elevate the camera with the up and down arrow keys.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////

#include "ZaminVaAseman.h"
#include "d3dUtility.h"

//#include "../../../../../ComputerGraphicsDirectX12Codes/homework5/Human/d3dUtility.h"
//
// Globals
//
#define SizeOfObject 12
IDirect3DDevice9* Device = 0;

const int Width = 600;
const int Height = 600;

IDirect3DTexture9* flore = 0;
IDirect3DTexture9* sky = 0;

ID3DXMesh* Objects[SizeOfObject] = { 0, 0, 0, 0 };
D3DXMATRIX  Worlds[SizeOfObject];
D3DXMATRIX  WorldsSkyFlore[2];
ZaminVaAseman* zamin = 0;
ZaminVaAseman* aseman = 0;
D3DMATERIAL9 Mtrls[SizeOfObject];

//
// Framework Functions
//
bool Setup()
{
	//
	// Create objects.
	//
	zamin = new ZaminVaAseman(Device);
	aseman = new ZaminVaAseman(Device);


	D3DXCreateBox(Device, 1.0f, 1.0f, 0.5f, &Objects[0], 0);             // head
	D3DXCreateBox(Device, 2.0f, 1.9f, 0.55f, &Objects[1], 0);            // body
	D3DXCreateSphere(Device, 0.1f, 20, 20, &Objects[2], 0);              // left eye 
	D3DXCreateSphere(Device, 0.1f, 20, 20, &Objects[3], 0);              // right eye
	D3DXCreateSphere(Device, 0.06f, 20, 20, &Objects[4], 0);             // left pupil
	D3DXCreateSphere(Device, 0.06f, 20, 20, &Objects[5], 0);             // right pupil
	D3DXCreateBox(Device, 0.5f, 1.52f, 0.25f, &Objects[6], 0);           // left foot
	D3DXCreateBox(Device, 0.5f, 1.52f, 0.25f, &Objects[7], 0);           // right foot
	D3DXCreateBox(Device, 0.6f, 0.1f, 0.06f, &Objects[8], 0);            // mouth
	D3DXCreateBox(Device, 1.7f, 0.3f, 0.25f, &Objects[9], 0);            // left hand
	D3DXCreateBox(Device, 1.7f, 0.3f, 0.25f, &Objects[10], 0);           // right hand
	D3DXCreateSphere(Device, 0.0f, 20, 20, &Objects[11], 0);


	//
	// Build world matrices - position the objects in world space.
	//

	D3DXMatrixTranslation(&Worlds[0], 0.0f, 2.1f, 0.0f);                 // head
	D3DXMatrixTranslation(&Worlds[1], 0.0f, 0.7f, 0.0f);                 // body
	D3DXMatrixTranslation(&Worlds[2], 0.235f, 2.35f, -0.27f);            // left eye
	D3DXMatrixTranslation(&Worlds[3], -0.235f, 2.35f, -0.27f);           // right eye
	D3DXMatrixTranslation(&Worlds[4], 0.235f, 2.35f, -0.33f);            // left pupil
	D3DXMatrixTranslation(&Worlds[5], -0.235f, 2.35f, -0.33f);           // right pupil
	D3DXMatrixTranslation(&Worlds[6], -0.5f, -0.9f, 0.0f);               // left foot
	D3DXMatrixTranslation(&Worlds[7], 0.5f, -0.9f, 0.0f);                // right foot
	D3DXMatrixTranslation(&Worlds[8], 0.0f, 1.85f, -0.25f);              // mouth
	D3DXMatrixTranslation(&Worlds[9], 1.5f, 1.1f, 0.0f);                 // left hand
	D3DXMatrixTranslation(&Worlds[10], -1.5f, 1.1f, 0.0f);               // right hand
	D3DXMatrixTranslation(&Worlds[11], -4.5f, 1.1f, 0.0f);               // right hand
	D3DXMatrixTranslation(&WorldsSkyFlore[0], 0.0f,  0.0f, 0.0f);        // Flore
	D3DXMatrixTranslation(&WorldsSkyFlore[1], 0.0f,  0.0f, 0.0f);        // sky




	// rotation  
	D3DXMATRIX rotate_zamin,rotate_aseman;
	D3DXMATRIX move_zamin,move_aseman;
	D3DXMatrixRotationX(&rotate_zamin, D3DX_PI * 0.5f);
	D3DXMatrixRotationX(&rotate_aseman, D3DX_PI * -0.5f);
	D3DXMatrixTranslation(& WorldsSkyFlore[0],0.0f,0.0f,0.0f);
	D3DXMatrixTranslation(& WorldsSkyFlore[1],0.0f,0.0f,0.0f);
	D3DXMatrixTranslation(&move_zamin,0.0f,-2.65f,0.0f);
	D3DXMatrixTranslation(&move_aseman,0.0f,20.0f,0.0f);
	WorldsSkyFlore[0]= rotate_zamin * move_zamin;
	WorldsSkyFlore[1]= rotate_aseman * move_aseman;

	
	

	//
	// Setup the object's materials.
	//

	Mtrls[0] = d3d::YELLOW_MTRL;
	Mtrls[1] = d3d::BLUE_MTRL;
	Mtrls[2] = d3d::WHITE_MTRL;
	Mtrls[3] = d3d::WHITE_MTRL;
	Mtrls[4] = d3d::GREEN_MTRL;
	Mtrls[5] = d3d::GREEN_MTRL;
	Mtrls[6] = d3d::YELLOW_MTRL;
	Mtrls[7] = d3d::YELLOW_MTRL;
	Mtrls[8] = d3d::RED_MTRL;
	Mtrls[9] = d3d::YELLOW_MTRL;
	Mtrls[10] = d3d::YELLOW_MTRL;
	Mtrls[11] = d3d::BLUE_MTRL;

	D3DXCreateTextureFromFile(
		Device,
		L"checkboard.dds",
		&flore);
	D3DXCreateTextureFromFile(
		Device,
		L"ice.dds",
		& sky);
	

	//
	// Setup a directional light.
	//

	D3DXVECTOR3 dir(1.0f, -0.0f, 0.25f);
	D3DXCOLOR   c = d3d::WHITE;
	D3DLIGHT9 dirLight = d3d::InitDirectionalLight(&dir, &c);

	//
	// Set and Enable the light.
	//

	Device->SetLight(0, &dirLight);
	Device->LightEnable(0, true);

	//
	// Set lighting related render states.
	//

	Device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	Device->SetRenderState(D3DRS_SPECULARENABLE, false);

	//
	// Set the projection matrix.
	//

	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(
		&proj,
		D3DX_PI * 0.25f, // 45 - degree
		(float)Width / (float)Height,
		1.0f,
		1000.0f);
	Device->SetTransform(D3DTS_PROJECTION, &proj);

	return true;
}

void Cleanup()
{
	for (int i = 0; i < SizeOfObject; i++)
		d3d::Release<ID3DXMesh*>(Objects[i]);
}

bool Display(float timeDelta)
{
	if (Device)
	{
		// 
		// Update the scene: update camera position.
		//

		static float angle = (3.0f * D3DX_PI) / 2.0f;
		static float height = 5.0f;

		if (::GetAsyncKeyState(VK_LEFT) & 0x8000f)
			angle -= 1 * timeDelta;

		if (::GetAsyncKeyState(VK_RIGHT) & 0x8000f)
			angle += 1 * timeDelta;

		if (::GetAsyncKeyState(VK_UP) & 0x8000f)
			height += 10 * timeDelta;

		if (::GetAsyncKeyState(VK_DOWN) & 0x8000f)
			height -= 10 * timeDelta;

		D3DXVECTOR3 position(cosf(angle) * 7.0f, height, sinf(angle) * 7.0f);
		D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
		D3DXMATRIX V;
		D3DXMatrixLookAtLH(&V, &position, &target, &up);

		Device->SetTransform(D3DTS_VIEW, &V);

		//
		// Draw the scene:
		//
		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
		Device->BeginScene();

		for (int i = 0; i < SizeOfObject; i++)
		{
			// set material and world matrix for ith object, then render
			// the ith object.
			Device->SetMaterial(&Mtrls[i]);
			Device->SetTransform(D3DTS_WORLD, &Worlds[i]);

			Objects[i]->DrawSubset(0);
			Device->SetTexture(0, flore);
			Device->SetTexture(0, sky);

		}
		zamin->draw(&WorldsSkyFlore[0], &Mtrls[3], flore);
		aseman->draw(&WorldsSkyFlore[1], &Mtrls[3], sky);
		Device->EndScene();
		Device->Present(0, 0, 0, 0);
	}
	return true;
}


//
// WndProc
//
LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			::DestroyWindow(hwnd);
		break;
	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}

//
// WinMain
//
int WINAPI WinMain(HINSTANCE hinstance,
	HINSTANCE prevInstance,
	PSTR cmdLine,
	int showCmd)
{
	if (!d3d::InitD3D(hinstance,
		Width, Height, true, D3DDEVTYPE_HAL, &Device))
	{
		::MessageBox(0, L"InitD3D() - FAILED", 0, 0);
		return 0;
	}

	if (!Setup())
	{
		::MessageBox(0, L"Setup() - FAILED", 0, 0);
		return 0;
	}

	d3d::EnterMsgLoop(Display);

	Cleanup();

	Device->Release();

	return 0;
}