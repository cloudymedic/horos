/*=========================================================================
 This file is part of the Horos Project (www.horosproject.org)
 
 Horos is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, �version 3 of the License.
 
 The Horos Project was based originally upon the OsiriX Project which at the time of
 the code fork was licensed as a LGPL project.  However, not all of the the source-code
 was properly documented and file headers were not all updated with the appropriate
 license terms. The Horos Project, originally was licensed under the  GNU GPL license.
 However, contributors to the software since that time have agreed to modify the license
 to the GNU LGPL in order to be conform to the changes previously made to the
 OsiriX Project.
 
 Horos is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY EXPRESS OR IMPLIED, INCLUDING ANY WARRANTY OF
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE OR USE. �See the
 GNU Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public License
 along with Horos. �If not, see http://www.gnu.org/licenses/lgpl.html
 
 Prior versions of this file were published by the OsiriX team pursuant to
 the below notice and licensing protocol.
 ============================================================================
 Program: � OsiriX
 �Copyright (c) OsiriX Team
 �All rights reserved.
 �Distributed under GNU - LGPL
 �
 �See http://www.osirix-viewer.com/copyright.html for details.
 � � This software is distributed WITHOUT ANY WARRANTY; without even
 � � the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 � � PURPOSE.
 ============================================================================*/

#import <AppKit/AppKit.h>

#import "DCMPix.h"
#import "Camera.h"

#ifdef __cplusplus
#import "VTKViewOSIRIX.h"
//#define id Id
#include <VTK/vtkCommand.h>
#include <VTK/vtkProperty.h>
#include <VTK/vtkActor.h>
#include <VTK/vtkPolyData.h>
#include <VTK/vtkRenderer.h>
#include <VTK/vtkRenderWindow.h>
#include <VTK/vtkRenderWindowInteractor.h>
#include <VTK/vtkVolume16Reader.h>
#include <VTK/vtkPolyDataMapper.h>
#include <VTK/vtkActor.h>
#include <VTK/vtkOutlineFilter.h>
#include <VTK/vtkImageReader.h>
#include <VTK/vtkImageImport.h>
#include <VTK/vtkCamera.h>
#include <VTK/vtkStripper.h>
#include <VTK/vtkLookupTable.h>
#include <VTK/vtkImageDataGeometryFilter.h>
#include <VTK/vtkProperty.h>
#include <VTK/vtkPolyDataNormals.h>
#include <VTK/vtkContourFilter.h>
#include <VTK/vtkImageData.h>
#include <VTK/vtkImageMapToColors.h>
#include <VTK/vtkImageActor.h>
#include <VTK/vtkLight.h>

#include <VTK/vtkPlane.h>
#include <VTK/vtkPlanes.h>
#include <VTK/vtkPlaneSource.h>
#include <VTK/vtkBoxWidget.h>
#include <VTK/vtkPlaneWidget.h>
#include <VTK/vtkPiecewiseFunction.h>
#include <VTK/vtkPiecewiseFunction.h>
#include <VTK/vtkColorTransferFunction.h>
#include <VTK/vtkVolumeProperty.h>
#include <VTK/vtkVolumeRayCastCompositeFunction.h>
#include <VTK/vtkVolumeRayCastMapper.h>
#include <VTK/vtkVolumeRayCastMIPFunction.h>

#include <VTK/vtkTransform.h>
#include <VTK/vtkSphere.h>
#include <VTK/vtkImplicitBoolean.h>
#include <VTK/vtkExtractGeometry.h>
#include <VTK/vtkDataSetMapper.h>
#include <VTK/vtkPicker.h>
#include <VTK/vtkCellPicker.h>
#include <VTK/vtkPointPicker.h>
#include <VTK/vtkLineSource.h>
#include <VTK/vtkPolyDataMapper2D.h>
#include <VTK/vtkActor2D.h>
#include <VTK/vtkExtractPolyDataGeometry.h>
#include <VTK/vtkProbeFilter.h>
#include <VTK/vtkCutter.h>
#include <VTK/vtkTransformPolyDataFilter.h>
#include <VTK/vtkXYPlotActor.h>
#include <VTK/vtkClipPolyData.h>
#include <VTK/vtkBox.h>
#include <VTK/vtkCallbackCommand.h>
#include <VTK/vtkImageResample.h>
#include <VTK/vtkDecimatePro.h>
#include <VTK/vtkSmoothPolyDataFilter.h>
#include <VTK/vtkImageFlip.h>
#include <VTK/vtkTextActor.h>
#include <VTK/vtkAnnotatedCubeActor.h>
#include <VTK/vtkOrientationMarkerWidget.h>
#include <VTK/vtkTextProperty.h>
#ifdef _STEREO_VISION_
// Added SilvanWidmer 10-08-09
// ****************************
#include <VTK/vtkCocoaGLView.h>
#include <VTK/vtkCocoaRenderWindowInteractor.h>
#include <VTK/vtkCocoaRenderWindow.h>
#include <VTK/vtkParallelRenderManager.h>
#include <VTK/vtkRendererCollection.h>
#include <VTK/vtkCallbackCommand.h>
#import "VTKStereoSRView.h>
// ****************************
#endif

//#undef id

class vtkMyCallback;

#else
typedef char* vtkTransform;
typedef char* vtkImageActor;
typedef char* vtkImageMapToColors;
typedef char* vtkLookupTable;
typedef char* vtkImageReslice;
typedef char* vtkImageImport;
typedef char* vtkCamera;
typedef char* vtkActor;
typedef char* vtkPolyDataMapper;
typedef char* vtkOutlineFilter;
typedef char* vtkLineWidget;

typedef char* vtkTextActor;
typedef char* vtkVolumeRayCastMapper;
typedef char* vtkVolumeRayCastMIPFunction;
typedef char* vtkVolume;


typedef char* vtkPiecewiseFunction;
typedef char* vtkVolumeTextureMapper2D;
typedef char* vtkPolyData;
typedef char* vtkVolumeProperty;
typedef char* vtkPolyDataMapper2D;

typedef char* vtkColorTransferFunction;
typedef char* vtkActor2D;
typedef char* vtkMyCallback;
typedef char* vtkPlaneWidget;
typedef char* vtkBoxWidget;
typedef char* vtkImageFlip;
typedef char* vtkImageResample;
typedef char* vtkMatrix4x4;
typedef char* vtkDecimatePro;
typedef char* vtkSmoothPolyDataFilter;
typedef char* vtkContourFilter;
typedef char* vtkPolyDataNormals;
typedef char* vtkRenderer;
typedef char* vtkOrientationMarkerWidget;

#ifdef _STEREO_VISION_
// ****************************
// Added SilvanWidmer 10-08-09
typedef char* vtkCocoaRenderWindowInteractor;
typedef char* vtkCocoaRenderWindow;
typedef char* vtkParallelRenderManager;
typedef	char* vtkRenderWindow;
typedef char* vtkRendererCollection;
typedef char* vtkCocoaGLView;
typedef char* vtkCallbackCommand;
typedef char* VTKStereoSRView;
// ****************************
#endif

#endif

#include <Accelerate/Accelerate.h>
#import "ViewerController.h"
#import "WaitRendering.h"

@class Camera;
@class SRController;
@class DICOMExport;

#ifdef _STEREO_VISION_
typedef struct renderSurface
{
	long actor;
	float resolution;
	float transparency;
	float r;
	float g;
	float b;
	float isocontour;
	float decimateVal;
	BOOL useDecimate;
	BOOL useSmooth;
	long smoothVal;
} renderSurface;

#endif

#ifdef __cplusplus
#else
#define VTKView NSView
#endif

/** \brief Surface Rendering View */
@interface SRView : VTKView <NSDraggingSource, NSPasteboardItemDataProvider>
{
	int							projectionMode;
    NSMutableArray				*blendingPixList;
    DCMPix						*blendingLastObject, *blendingFirstObject;
    float						*blendingData, blendingFactor;
	ViewerController			*blendingController;
	vtkImageImport				*blendingReader;
	vtkImageFlip				*flip, *blendingFlip;
	
	vtkTextActor				*textX;
	vtkTextActor				*oText[ 4];
	
	NSCursor					*cursor;
	BOOL						cursorSet;
	
    NSMutableArray				*pixList;
    DCMPix						*firstObject;
    float						*data, *dataFRGB;
    ToolMode					currentTool;
	float						cosines[ 9];
	float						blendingcosines[ 9];

	IBOutlet NSWindow			*export3DWindow;
	IBOutlet NSSlider			*framesSlider;
	IBOutlet NSMatrix			*rotation;
	
	IBOutlet NSWindow			*export3DVRWindow;
	IBOutlet NSMatrix			*VRFrames;
	
	IBOutlet NSColorWell		*backColor;
	
	double						camPosition[ 3];
	double						camFocal[ 3];
	
	long						numberOfFrames;
	float						rotationValue;
	long						rotationOrientation;
	
//	vtkCallbackCommand			*cbStart;
	
	// DICOM export
	IBOutlet NSWindow			*exportDCMWindow;
	IBOutlet NSSlider			*dcmframesSlider;
	IBOutlet NSMatrix			*dcmExportMode, *dcmrotation, *dcmorientation;
	IBOutlet NSBox				*dcmBox;
	IBOutlet NSTextField		*dcmSeriesName;
	
	vtkRenderer					*aRenderer;
    vtkCamera					*aCamera;

    vtkActor					*outlineRect;
    vtkPolyDataMapper			*mapOutline;
    vtkOutlineFilter			*outlineData;
	
	vtkImageImport				*reader;
	
	BOOL						noWaitDialog;
	WaitRendering				*splash;
	DICOMExport					*exportDCM;
	
	vtkImageResample			*isoResample;
	vtkDecimatePro				*isoDeci[ 2];
	vtkSmoothPolyDataFilter		*isoSmoother[ 2];
	vtkContourFilter			*isoExtractor [ 2];
	vtkPolyDataNormals			*isoNormals [ 2];
	vtkPolyDataMapper			*isoMapper [ 2];
	vtkActor					*iso [ 2];

	vtkImageResample			*BisoResample;
	vtkDecimatePro				*BisoDeci[ 2];
	vtkSmoothPolyDataFilter		*BisoSmoother[ 2];
	vtkContourFilter			*BisoExtractor [ 2];
	vtkPolyDataNormals			*BisoNormals [ 2];
	vtkPolyDataMapper			*BisoMapper [ 2];
	vtkActor					*Biso [ 2];
	
	vtkMatrix4x4				*matrice;
	vtkMatrix4x4				*matriceBlending;
	vtkOrientationMarkerWidget	*orientationWidget;
	
	NSDate						*startRenderingTime;
	
	NSMutableArray				*point3DActorArray;
	NSMutableArray				*point3DPositionsArray;
	NSMutableArray				*point3DRadiusArray;
	NSMutableArray				*point3DColorsArray;
	
	NSMutableArray				*point3DDisplayPositionArray;
	NSMutableArray				*point3DTextArray;
	NSMutableArray				*point3DPositionsStringsArray;
	NSMutableArray				*point3DTextSizesArray;
	NSMutableArray				*point3DTextColorsArray;
	
	BOOL						display3DPoints;
	IBOutlet NSPanel			*point3DInfoPanel;
	IBOutlet NSTextField		*point3DPositionTextField;
	IBOutlet NSButton			*point3DDisplayPositionButton;
	IBOutlet NSSlider			*point3DRadiusSlider, *point3DTextSizeSlider;
	IBOutlet NSColorWell		*point3DColorWell, *point3DTextColorWell;
	IBOutlet NSButton			*point3DPropagateToAll, *point3DSetDefault;
	IBOutlet SRController		*controller;
	float						point3DDefaultRadius, point3DDefaultColorRed, point3DDefaultColorGreen, point3DDefaultColorBlue, point3DDefaultColorAlpha;
	
	BOOL						_dragInProgress;
	NSTimer						*_mouseDownTimer;
	NSImage						*destinationImage;
	
	NSPoint						_mouseLocStart;  // mouseDown start point
	BOOL						_resizeFrame;
	ToolMode					_tool;
	
	NSRect						savedViewSizeFrame;

	// 3DConnexion SpaceNavigator
	NSTimer			*snCloseEventTimer;
	BOOL			snStopped;
	UInt16			snConnexionClientID;
	
#ifdef _STEREO_VISION_
	//Added SilvanWidmer 10-08-09
	NSWindow						*LeftFullScreenWindow; 
	NSWindow						*RightFullScreenWindow;   
	BOOL							StereoVisionOn;
	vtkCocoaGLView					*leftView;
	VTKStereoSRView					*rightView;
	NSWindow						*rootWindow;
	NSView							*LeftContentView;
	NSRect							rootSize;
	NSSize							rootBorder;
	
	renderSurface					first;
	renderSurface					second;
	vtkCallbackCommand				*rightResponder;
#endif
	
}

#ifdef _STEREO_VISION_
@property(readwrite) BOOL StereoVisionOn; 
@property(readonly) ToolMode currentTool;
#endif

-(unsigned char*) getRawPixels:(long*) width :(long*) height :(long*) spp :(long*) bpp :(BOOL) screenCapture :(BOOL) force8bits;
-(NSDate*) startRenderingTime;
-(void) newStartRenderingTime;
-(void) runRendering;
-(void) startRendering;
-(void) stopRendering;
-(void) setViewSizeToMatrix3DExport;
-(void) setCurrentTool:(ToolMode) i;
-(id) initWithFrame:(NSRect)frame;
-(short) setPixSource:(NSMutableArray*)pix :(float*) volumeData;
-(void) dealloc;
-(void) setBlendingPixSource:(ViewerController*) bC;
- (void) changeActor:(long) actor :(float) resolution :(float) transparency :(float) r :(float) g :(float) b :(float) isocontour :(BOOL) useDecimate :(float) decimateVal :(BOOL) useSmooth :(long) smoothVal;
-(void) deleteActor:(long) actor;
-(void) BchangeActor:(long) actor :(float) resolution :(float) transparency :(float) r :(float) g :(float) b :(float) isocontour :(BOOL) useDecimate :(float) decimateVal :(BOOL) useSmooth :(long) smoothVal;
-(void) BdeleteActor:(long) actor;
-(IBAction) endQuicktimeSettings:(id) sender;
-(IBAction) exportQuicktime :(id) sender;
//-(IBAction) endQuicktimeVRSettings:(id) sender;
- (IBAction) setCurrentdcmExport:(id) sender;
-(IBAction) endDCMExportSettings:(id) sender;
-(void) exportDICOMFile:(id) sender;
-(float) rotation;
-(float) numberOfFrames;
-(void) Azimuth:(float) z;
-(void) Vertical:(float) a;
-(NSImage*) nsimageQuicktime;
-(NSImage*) nsimage:(BOOL) q;
-(IBAction) export3DFileFormat :(id) sender;
-(IBAction) SwitchStereoMode :(id) sender;
- (void) setCamera: (Camera*) cam;
- (Camera*) camera;
-(void) switchOrientationWidget:(id) sender;
- (void) computeOrientationText;
- (void) getOrientation: (float*) o;
-(void) saView:(id) sender;
-(void) axView:(id) sender;
-(void) coView:(id) sender;
-(void) saViewOpposite:(id) sender;
- (IBAction)changeColor:(id)sender;
-(IBAction) switchProjection:(id) sender;
-(void) restoreViewSizeAfterMatrix3DExport;

// 3D Points
- (void) add3DPoint: (double) x : (double) y : (double) z : (float) radius : (float) r : (float) g : (float) b;
- (void) add3DPoint: (double) x : (double) y : (double) z;
- (void) add3DPointActor: (vtkActor*) actor;
- (void) addRandomPoints: (int) n : (int) r;
- (void) throw3DPointOnSurface: (double) x : (double) y;
- (void) setDisplay3DPoints: (BOOL) on;
- (void) toggleDisplay3DPoints;
- (BOOL) isAny3DPointSelected;
- (unsigned int) selected3DPointIndex;
- (void) unselectAllActors;
- (void) remove3DPointAtIndex: (unsigned int) index;
- (void) removeSelected3DPoint;
- (IBAction) IBSetSelected3DPointColor: (id) sender;
- (IBAction) IBSetSelected3DPointRadius: (id) sender;
- (IBAction) IBPropagate3DPointsSettings: (id) sender;
- (void) setSelected3DPointColor: (NSColor*) color;
- (void) setAll3DPointsColor: (NSColor*) color;
- (void) set3DPointAtIndex:(unsigned int) index Color: (NSColor*) color;
- (void) setSelected3DPointRadius: (float) radius;
- (void) setAll3DPointsRadius: (float) radius;
- (void) set3DPointAtIndex:(unsigned int) index Radius: (float) radius;
- (IBAction) save3DPointsDefaultProperties: (id) sender;
- (void) load3DPointsDefaultProperties;
- (void) convert3Dto2Dpoint:(double*) pt3D :(double*) pt2D;

// 3D Points annotations
- (IBAction) IBSetSelected3DPointAnnotation: (id) sender;
- (void) setAnnotationWithPosition:(int)displayPosition for3DPointAtIndex:(unsigned int) index;
- (void) setAnnotation:(const char*) annotation for3DPointAtIndex:(unsigned int) index;
- (void) displayAnnotationFor3DPointAtIndex:(unsigned int) index;
- (void) hideAnnotationFor3DPointAtIndex:(unsigned int) index;
- (IBAction) IBSetSelected3DPointAnnotationColor: (id) sender;
- (IBAction) IBSetSelected3DPointAnnotationSize: (id) sender;

-(void) setCursorForView: (ToolMode) tool;

//Dragging
- (void) startDrag:(NSTimer*)theTimer;
- (void)deleteMouseDownTimer;
-(void) squareView:(id) sender;

- (void)yaw:(float)degrees;
- (void)panX:(float)x Y:(float)y;

// 3DConnexion SpaceNavigator
- (void)connect2SpaceNavigator;
void SRSpaceNavigatorMessageHandler(io_connect_t connection, natural_t messageType, void *messageArgument);
#ifdef _STEREO_VISION_
//Added SilvanWidmer 27-08-09
- (ToolMode) getTool: (NSEvent*) event;
#endif

@end
