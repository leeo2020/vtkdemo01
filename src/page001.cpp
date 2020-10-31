#include <vtkSphereSource.h>
#include <vtkCylinderSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>
#include <vtkAutoInit.h>  
#include <vtkInteractorStyleTrackballCamera.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

int main()
{
	vtkSmartPointer<vtkCylinderSource>cylinder =
		vtkSmartPointer<vtkCylinderSource>::New();
	cylinder->SetHeight(3.0);
	cylinder->SetRadius(1.0);
	cylinder->SetResolution(10);

	vtkSmartPointer<vtkPolyDataMapper>cylinderMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	cylinderMapper->SetInputConnection(cylinder->GetOutputPort());

	vtkSmartPointer<vtkActor>cylinderActor =
		vtkSmartPointer<vtkActor>::New();
	cylinderActor->SetMapper(cylinderMapper);

	vtkSmartPointer<vtkRenderer>renderer =
		vtkSmartPointer<vtkRenderer>::New();
	renderer->AddActor(cylinderActor);
	renderer->SetBackground(0.1, 0.2, 0.4);

	vtkSmartPointer<vtkRenderWindow>renWin =
		vtkSmartPointer<vtkRenderWindow>::New();
	renWin->AddRenderer(renderer);
	renWin->SetSize(300, 300);

	vtkSmartPointer<vtkRenderWindowInteractor>iren =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	iren->SetRenderWindow(renWin);

	vtkSmartPointer<vtkInteractorStyleTrackballCamera>style =
		vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
	iren->SetInteractorStyle(style);

	iren->Initialize();
	iren->Start();


	return EXIT_SUCCESS;
}
