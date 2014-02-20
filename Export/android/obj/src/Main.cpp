#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_MainCharacter
#include <MainCharacter.h>
#endif
#ifndef INCLUDED_Platform
#include <Platform.h>
#endif
#ifndef INCLUDED_PlatformManager
#include <PlatformManager.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_display_Stage
#include <flash/display/Stage.h>
#endif
#ifndef INCLUDED_flash_events_AccelerometerEvent
#include <flash/events/AccelerometerEvent.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_KeyboardEvent
#include <flash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flash_sensors_Accelerometer
#include <flash/sensors/Accelerometer.h>
#endif
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flash_ui_Keyboard
#include <flash/ui/Keyboard.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_PUSH("Main::new","Main.hx",21);
{
	HX_STACK_LINE(33)
	this->cameraMove = false;
	HX_STACK_LINE(32)
	this->prevDistance = (int)0;
	HX_STACK_LINE(31)
	this->distance = (int)0;
	HX_STACK_LINE(42)
	super::__construct();
	HX_STACK_LINE(43)
	this->platformsOnStage = ::List_obj::__new();
	HX_STACK_LINE(46)
	this->textField = ::flash::text::TextField_obj::__new();
	HX_STACK_LINE(47)
	this->acc = ::flash::sensors::Accelerometer_obj::__new();
	HX_STACK_LINE(48)
	this->characterSpeed = ::flash::geom::Point_obj::__new(null(),null());
	HX_STACK_LINE(50)
	this->characterSpeed->x = (int)30;
	HX_STACK_LINE(51)
	this->characterSpeed->y = (int)2;
	HX_STACK_LINE(53)
	this->acceleration = (int)1;
	HX_STACK_LINE(55)
	this->textField->set_x((int)50);
	HX_STACK_LINE(56)
	this->textField->set_y((int)50);
	HX_STACK_LINE(57)
	this->textField->set_width((int)200);
	HX_STACK_LINE(59)
	this->addChild(this->textField);
	HX_STACK_LINE(61)
	this->characterContainer = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(62)
	this->character = ::MainCharacter_obj::__new();
	HX_STACK_LINE(63)
	this->characterContainer->addChild(this->character);
	HX_STACK_LINE(64)
	this->character->set_x((int)300);
	HX_STACK_LINE(65)
	this->character->set_y((int)300);
	HX_STACK_LINE(68)
	{
		HX_STACK_LINE(68)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(68)
		while(((_g < (int)100))){
			HX_STACK_LINE(68)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(71)
			::Platform pltfrm;		HX_STACK_VAR(pltfrm,"pltfrm");
			HX_STACK_LINE(72)
			if (((i == (int)0))){
				HX_STACK_LINE(72)
				pltfrm = ((  (((::PlatformManager_obj::_instance == null()))) ? ::PlatformManager(::PlatformManager_obj::_instance = ::PlatformManager_obj::__new()) : ::PlatformManager(::PlatformManager_obj::_instance) ))->getPlatform((this->character->get_y() + this->character->get_height()),this->character->get_x(),true);
			}
			else{
				HX_STACK_LINE(74)
				if (((i == (int)1))){
					HX_STACK_LINE(74)
					pltfrm = ((  (((::PlatformManager_obj::_instance == null()))) ? ::PlatformManager(::PlatformManager_obj::_instance = ::PlatformManager_obj::__new()) : ::PlatformManager(::PlatformManager_obj::_instance) ))->getPlatform((int)200,(int)350,true);
				}
				else{
					HX_STACK_LINE(76)
					if (((i == (int)2))){
						HX_STACK_LINE(76)
						pltfrm = ((  (((::PlatformManager_obj::_instance == null()))) ? ::PlatformManager(::PlatformManager_obj::_instance = ::PlatformManager_obj::__new()) : ::PlatformManager(::PlatformManager_obj::_instance) ))->getPlatform((int)-100,(int)250,true);
					}
					else{
						HX_STACK_LINE(79)
						Float hght = (int)-40;		HX_STACK_VAR(hght,"hght");
						HX_STACK_LINE(80)
						pltfrm = ((  (((::PlatformManager_obj::_instance == null()))) ? ::PlatformManager(::PlatformManager_obj::_instance = ::PlatformManager_obj::__new()) : ::PlatformManager(::PlatformManager_obj::_instance) ))->getPlatform(hght,this->get_stage()->get_stageWidth(),null());
					}
				}
			}
			HX_STACK_LINE(82)
			this->platformsOnStage->add(pltfrm);
			HX_STACK_LINE(83)
			this->characterContainer->addChild(pltfrm);
		}
	}
	HX_STACK_LINE(93)
	this->addChild(this->characterContainer);
	HX_STACK_LINE(95)
	this->get_stage()->addEventListener(::flash::events::KeyboardEvent_obj::KEY_DOWN,this->onKeyDown_dyn(),null(),null(),null());
	HX_STACK_LINE(96)
	this->get_stage()->addEventListener(::flash::events::KeyboardEvent_obj::KEY_UP,this->OnKeyUp_dyn(),null(),null(),null());
	HX_STACK_LINE(97)
	this->get_stage()->addEventListener(::flash::events::Event_obj::ENTER_FRAME,this->OnEnterFrame_dyn(),null(),null(),null());
	HX_STACK_LINE(99)
	this->acc->addEventListener(::flash::events::AccelerometerEvent_obj::UPDATE,this->OnAcceleromterChange_dyn(),null(),null(),null());
}
;
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

bool Main_obj::collidingWithPlatform( ::MainCharacter obj1,::Platform obj2){
	HX_STACK_PUSH("Main::collidingWithPlatform","Main.hx",196);
	HX_STACK_THIS(this);
	HX_STACK_ARG(obj1,"obj1");
	HX_STACK_ARG(obj2,"obj2");
	HX_STACK_LINE(197)
	::flash::geom::Rectangle rect1 = ::flash::geom::Rectangle_obj::__new(obj1->get_x(),obj1->get_y(),obj1->get_width(),obj1->get_height());		HX_STACK_VAR(rect1,"rect1");
	HX_STACK_LINE(198)
	::flash::geom::Rectangle rect2 = ::flash::geom::Rectangle_obj::__new(obj2->get_x(),obj2->get_y(),obj2->get_width(),obj2->get_height());		HX_STACK_VAR(rect2,"rect2");
	HX_STACK_LINE(200)
	return rect1->intersects(rect2);
}


HX_DEFINE_DYNAMIC_FUNC2(Main_obj,collidingWithPlatform,return )

Void Main_obj::OnAcceleromterChange( ::flash::events::AccelerometerEvent e){
{
		HX_STACK_PUSH("Main::OnAcceleromterChange","Main.hx",186);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(189)
		Float speed = (this->characterSpeed->x * e->accelerationX);		HX_STACK_VAR(speed,"speed");
		HX_STACK_LINE(191)
		if (((bool((e->accelerationX < -0.1)) || bool((e->accelerationX > 0.1))))){
			HX_STACK_LINE(192)
			::MainCharacter _g = this->character;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(192)
			_g->set_x((_g->get_x() - speed));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,OnAcceleromterChange,(void))

Void Main_obj::OnEnterFrame( ::flash::events::Event e){
{
		HX_STACK_PUSH("Main::OnEnterFrame","Main.hx",119);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(124)
		Float currentHeight = this->character->get_y();		HX_STACK_VAR(currentHeight,"currentHeight");
		HX_STACK_LINE(125)
		if (((currentHeight < (int)0))){
			HX_STACK_LINE(125)
			currentHeight = ((currentHeight * (int)-1) + this->get_stage()->get_stageHeight());
		}
		else{
			HX_STACK_LINE(127)
			currentHeight = (this->get_stage()->get_stageHeight() - currentHeight);
		}
		HX_STACK_LINE(130)
		if (((this->prevDistance < currentHeight))){
			HX_STACK_LINE(130)
			this->distance = currentHeight;
		}
		HX_STACK_LINE(138)
		if (((this->character->get_x() > this->get_stage()->get_stageWidth()))){
			HX_STACK_LINE(138)
			this->character->set_x(((int)0 - this->character->get_width()));
		}
		HX_STACK_LINE(141)
		if (((this->character->get_x() < ((int)0 - this->character->get_width())))){
			HX_STACK_LINE(141)
			this->character->set_x(this->get_stage()->get_stageWidth());
		}
		HX_STACK_LINE(146)
		for(::cpp::FastIterator_obj< ::Platform > *__it = ::cpp::CreateFastIterator< ::Platform >(this->platformsOnStage->iterator());  __it->hasNext(); ){
			::Platform p = __it->next();
			if ((this->collidingWithPlatform(this->character,p))){
				HX_STACK_LINE(147)
				if (((bool((this->characterSpeed->y > (int)0)) && bool(((this->character->get_y() + this->character->get_height()) < (p->get_y() + p->get_height())))))){
					HX_STACK_LINE(148)
					this->characterSpeed->y = (int)-25;
				}
			}
;
		}
		HX_STACK_LINE(156)
		if (((this->characterSpeed->y < (int)30))){
			HX_STACK_LINE(156)
			hx::AddEq(this->characterSpeed->y,this->acceleration);
		}
		HX_STACK_LINE(160)
		{
			HX_STACK_LINE(160)
			::MainCharacter _g = this->character;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(160)
			_g->set_y((_g->get_y() + this->characterSpeed->y));
		}
		HX_STACK_LINE(163)
		if (((this->prevDistance != (int)0))){
			HX_STACK_LINE(164)
			::flash::display::Sprite _g = this->characterContainer;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(164)
			_g->set_y((_g->get_y() + ((this->distance - this->prevDistance))));
		}
		HX_STACK_LINE(167)
		this->textField->set_text(::Std_obj::string(this->distance));
		HX_STACK_LINE(169)
		if ((((this->character->get_y() + this->character->get_height()) > this->get_stage()->get_stageHeight()))){
			HX_STACK_LINE(170)
			this->characterSpeed->y = (int)0;
			HX_STACK_LINE(171)
			this->character->set_y((this->get_stage()->get_stageHeight() - this->character->get_height()));
		}
		HX_STACK_LINE(175)
		if ((this->moveLeft)){
			HX_STACK_LINE(176)
			{
				HX_STACK_LINE(176)
				::MainCharacter _g = this->character;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(176)
				_g->set_x((_g->get_x() - (int)5));
			}
			HX_STACK_LINE(177)
			{
				HX_STACK_LINE(177)
				::MainCharacter _g = this->character;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(177)
				_g->set_y((_g->get_y() - (int)5));
			}
		}
		HX_STACK_LINE(179)
		if ((this->moveRight)){
			HX_STACK_LINE(180)
			{
				HX_STACK_LINE(180)
				::MainCharacter _g = this->character;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(180)
				_g->set_y((_g->get_y() + (int)5));
			}
			HX_STACK_LINE(181)
			{
				HX_STACK_LINE(181)
				::MainCharacter _g = this->character;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(181)
				_g->set_x((_g->get_x() + (int)5));
			}
		}
		HX_STACK_LINE(183)
		this->prevDistance = this->distance;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,OnEnterFrame,(void))

Void Main_obj::onKeyDown( ::flash::events::KeyboardEvent e){
{
		HX_STACK_PUSH("Main::onKeyDown","Main.hx",108);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(108)
		int _switch_1 = (e->keyCode);
		if (  ( _switch_1==::flash::ui::Keyboard_obj::LEFT)){
			HX_STACK_LINE(111)
			this->moveLeft = true;
		}
		else if (  ( _switch_1==::flash::ui::Keyboard_obj::RIGHT)){
			HX_STACK_LINE(113)
			this->moveRight = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onKeyDown,(void))

Void Main_obj::OnKeyUp( ::flash::events::KeyboardEvent e){
{
		HX_STACK_PUSH("Main::OnKeyUp","Main.hx",102);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(104)
		this->moveLeft = false;
		HX_STACK_LINE(105)
		this->moveRight = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,OnKeyUp,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(acceleration,"acceleration");
	HX_MARK_MEMBER_NAME(characterAccel,"characterAccel");
	HX_MARK_MEMBER_NAME(characterSpeed,"characterSpeed");
	HX_MARK_MEMBER_NAME(cameraMove,"cameraMove");
	HX_MARK_MEMBER_NAME(prevDistance,"prevDistance");
	HX_MARK_MEMBER_NAME(distance,"distance");
	HX_MARK_MEMBER_NAME(jumping,"jumping");
	HX_MARK_MEMBER_NAME(platformsOnStage,"platformsOnStage");
	HX_MARK_MEMBER_NAME(acc,"acc");
	HX_MARK_MEMBER_NAME(textField,"textField");
	HX_MARK_MEMBER_NAME(moveRight,"moveRight");
	HX_MARK_MEMBER_NAME(moveLeft,"moveLeft");
	HX_MARK_MEMBER_NAME(character,"character");
	HX_MARK_MEMBER_NAME(characterContainer,"characterContainer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(acceleration,"acceleration");
	HX_VISIT_MEMBER_NAME(characterAccel,"characterAccel");
	HX_VISIT_MEMBER_NAME(characterSpeed,"characterSpeed");
	HX_VISIT_MEMBER_NAME(cameraMove,"cameraMove");
	HX_VISIT_MEMBER_NAME(prevDistance,"prevDistance");
	HX_VISIT_MEMBER_NAME(distance,"distance");
	HX_VISIT_MEMBER_NAME(jumping,"jumping");
	HX_VISIT_MEMBER_NAME(platformsOnStage,"platformsOnStage");
	HX_VISIT_MEMBER_NAME(acc,"acc");
	HX_VISIT_MEMBER_NAME(textField,"textField");
	HX_VISIT_MEMBER_NAME(moveRight,"moveRight");
	HX_VISIT_MEMBER_NAME(moveLeft,"moveLeft");
	HX_VISIT_MEMBER_NAME(character,"character");
	HX_VISIT_MEMBER_NAME(characterContainer,"characterContainer");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"acc") ) { return acc; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"OnKeyUp") ) { return OnKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"jumping") ) { return jumping; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { return distance; }
		if (HX_FIELD_EQ(inName,"moveLeft") ) { return moveLeft; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { return onKeyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"textField") ) { return textField; }
		if (HX_FIELD_EQ(inName,"moveRight") ) { return moveRight; }
		if (HX_FIELD_EQ(inName,"character") ) { return character; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"cameraMove") ) { return cameraMove; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"OnEnterFrame") ) { return OnEnterFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"acceleration") ) { return acceleration; }
		if (HX_FIELD_EQ(inName,"prevDistance") ) { return prevDistance; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"characterAccel") ) { return characterAccel; }
		if (HX_FIELD_EQ(inName,"characterSpeed") ) { return characterSpeed; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"platformsOnStage") ) { return platformsOnStage; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"characterContainer") ) { return characterContainer; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"OnAcceleromterChange") ) { return OnAcceleromterChange_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"collidingWithPlatform") ) { return collidingWithPlatform_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"acc") ) { acc=inValue.Cast< ::flash::sensors::Accelerometer >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"jumping") ) { jumping=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { distance=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"moveLeft") ) { moveLeft=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"textField") ) { textField=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		if (HX_FIELD_EQ(inName,"moveRight") ) { moveRight=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"character") ) { character=inValue.Cast< ::MainCharacter >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"cameraMove") ) { cameraMove=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"acceleration") ) { acceleration=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"prevDistance") ) { prevDistance=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"characterAccel") ) { characterAccel=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		if (HX_FIELD_EQ(inName,"characterSpeed") ) { characterSpeed=inValue.Cast< ::flash::geom::Point >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"platformsOnStage") ) { platformsOnStage=inValue.Cast< ::List >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"characterContainer") ) { characterContainer=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("acceleration"));
	outFields->push(HX_CSTRING("characterAccel"));
	outFields->push(HX_CSTRING("characterSpeed"));
	outFields->push(HX_CSTRING("cameraMove"));
	outFields->push(HX_CSTRING("prevDistance"));
	outFields->push(HX_CSTRING("distance"));
	outFields->push(HX_CSTRING("jumping"));
	outFields->push(HX_CSTRING("platformsOnStage"));
	outFields->push(HX_CSTRING("acc"));
	outFields->push(HX_CSTRING("textField"));
	outFields->push(HX_CSTRING("moveRight"));
	outFields->push(HX_CSTRING("moveLeft"));
	outFields->push(HX_CSTRING("character"));
	outFields->push(HX_CSTRING("characterContainer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("collidingWithPlatform"),
	HX_CSTRING("OnAcceleromterChange"),
	HX_CSTRING("OnEnterFrame"),
	HX_CSTRING("onKeyDown"),
	HX_CSTRING("OnKeyUp"),
	HX_CSTRING("acceleration"),
	HX_CSTRING("characterAccel"),
	HX_CSTRING("characterSpeed"),
	HX_CSTRING("cameraMove"),
	HX_CSTRING("prevDistance"),
	HX_CSTRING("distance"),
	HX_CSTRING("jumping"),
	HX_CSTRING("platformsOnStage"),
	HX_CSTRING("acc"),
	HX_CSTRING("textField"),
	HX_CSTRING("moveRight"),
	HX_CSTRING("moveLeft"),
	HX_CSTRING("character"),
	HX_CSTRING("characterContainer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

