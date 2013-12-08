#ifndef INCLUDED_Main
#define INCLUDED_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/display/Sprite.h>
HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS0(Main)
HX_DECLARE_CLASS0(MainCharacter)
HX_DECLARE_CLASS0(Platform)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,AccelerometerEvent)
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,events,KeyboardEvent)
HX_DECLARE_CLASS2(flash,geom,Point)
HX_DECLARE_CLASS2(flash,sensors,Accelerometer)
HX_DECLARE_CLASS2(flash,text,TextField)


class HXCPP_CLASS_ATTRIBUTES  Main_obj : public ::flash::display::Sprite_obj{
	public:
		typedef ::flash::display::Sprite_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Main"); }

		virtual bool collidingWithPlatform( ::MainCharacter obj1,::Platform obj2);
		Dynamic collidingWithPlatform_dyn();

		virtual Void OnAcceleromterChange( ::flash::events::AccelerometerEvent e);
		Dynamic OnAcceleromterChange_dyn();

		virtual Void OnEnterFrame( ::flash::events::Event e);
		Dynamic OnEnterFrame_dyn();

		virtual Void onKeyDown( ::flash::events::KeyboardEvent e);
		Dynamic onKeyDown_dyn();

		virtual Void OnKeyUp( ::flash::events::KeyboardEvent e);
		Dynamic OnKeyUp_dyn();

		Float acceleration;
		::flash::geom::Point characterAccel;
		::flash::geom::Point characterSpeed;
		bool jumping;
		::List platformsOnStage;
		::flash::sensors::Accelerometer acc;
		::flash::text::TextField textField;
		bool moveRight;
		bool moveLeft;
		::MainCharacter character;
		::flash::display::Sprite characterContainer;
};


#endif /* INCLUDED_Main */ 
