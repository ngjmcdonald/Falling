#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_events_AccelerometerEvent
#include <flash/events/AccelerometerEvent.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
namespace flash{
namespace events{

Void AccelerometerEvent_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< Float >  __o_timestamp,hx::Null< Float >  __o_accelerationX,hx::Null< Float >  __o_accelerationY,hx::Null< Float >  __o_accelerationZ)
{
HX_STACK_PUSH("AccelerometerEvent::new","flash/events/AccelerometerEvent.hx",18);
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
Float timestamp = __o_timestamp.Default(0);
Float accelerationX = __o_accelerationX.Default(0);
Float accelerationY = __o_accelerationY.Default(0);
Float accelerationZ = __o_accelerationZ.Default(0);
{
	HX_STACK_LINE(20)
	super::__construct(type,bubbles,cancelable);
	HX_STACK_LINE(22)
	this->timestamp = timestamp;
	HX_STACK_LINE(23)
	this->accelerationX = accelerationX;
	HX_STACK_LINE(24)
	this->accelerationY = accelerationY;
	HX_STACK_LINE(25)
	this->accelerationZ = accelerationZ;
}
;
	return null();
}

AccelerometerEvent_obj::~AccelerometerEvent_obj() { }

Dynamic AccelerometerEvent_obj::__CreateEmpty() { return  new AccelerometerEvent_obj; }
hx::ObjectPtr< AccelerometerEvent_obj > AccelerometerEvent_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,hx::Null< Float >  __o_timestamp,hx::Null< Float >  __o_accelerationX,hx::Null< Float >  __o_accelerationY,hx::Null< Float >  __o_accelerationZ)
{  hx::ObjectPtr< AccelerometerEvent_obj > result = new AccelerometerEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,__o_timestamp,__o_accelerationX,__o_accelerationY,__o_accelerationZ);
	return result;}

Dynamic AccelerometerEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AccelerometerEvent_obj > result = new AccelerometerEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

::String AccelerometerEvent_obj::toString( ){
	HX_STACK_PUSH("AccelerometerEvent::toString","flash/events/AccelerometerEvent.hx",37);
	HX_STACK_THIS(this);
	HX_STACK_LINE(37)
	return ((((((((((((((HX_CSTRING("[AccelerometerEvent type=") + this->get_type()) + HX_CSTRING(" bubbles=")) + ::Std_obj::string(this->get_bubbles())) + HX_CSTRING(" cancelable=")) + ::Std_obj::string(this->get_cancelable())) + HX_CSTRING(" timestamp=")) + this->timestamp) + HX_CSTRING(" accelerationX=")) + this->accelerationX) + HX_CSTRING(" accelerationY=")) + this->accelerationY) + HX_CSTRING(" accelerationZ=")) + this->accelerationZ) + HX_CSTRING("]"));
}


::flash::events::Event AccelerometerEvent_obj::clone( ){
	HX_STACK_PUSH("AccelerometerEvent::clone","flash/events/AccelerometerEvent.hx",30);
	HX_STACK_THIS(this);
	HX_STACK_LINE(30)
	return ::flash::events::AccelerometerEvent_obj::__new(this->get_type(),this->get_bubbles(),this->get_cancelable(),this->timestamp,this->accelerationX,this->accelerationY,this->accelerationZ);
}


::String AccelerometerEvent_obj::UPDATE;


AccelerometerEvent_obj::AccelerometerEvent_obj()
{
}

void AccelerometerEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AccelerometerEvent);
	HX_MARK_MEMBER_NAME(timestamp,"timestamp");
	HX_MARK_MEMBER_NAME(accelerationZ,"accelerationZ");
	HX_MARK_MEMBER_NAME(accelerationY,"accelerationY");
	HX_MARK_MEMBER_NAME(accelerationX,"accelerationX");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void AccelerometerEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(timestamp,"timestamp");
	HX_VISIT_MEMBER_NAME(accelerationZ,"accelerationZ");
	HX_VISIT_MEMBER_NAME(accelerationY,"accelerationY");
	HX_VISIT_MEMBER_NAME(accelerationX,"accelerationX");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic AccelerometerEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"UPDATE") ) { return UPDATE; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"timestamp") ) { return timestamp; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"accelerationZ") ) { return accelerationZ; }
		if (HX_FIELD_EQ(inName,"accelerationY") ) { return accelerationY; }
		if (HX_FIELD_EQ(inName,"accelerationX") ) { return accelerationX; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AccelerometerEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"UPDATE") ) { UPDATE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"timestamp") ) { timestamp=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"accelerationZ") ) { accelerationZ=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"accelerationY") ) { accelerationY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"accelerationX") ) { accelerationX=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AccelerometerEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("timestamp"));
	outFields->push(HX_CSTRING("accelerationZ"));
	outFields->push(HX_CSTRING("accelerationY"));
	outFields->push(HX_CSTRING("accelerationX"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("UPDATE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("clone"),
	HX_CSTRING("timestamp"),
	HX_CSTRING("accelerationZ"),
	HX_CSTRING("accelerationY"),
	HX_CSTRING("accelerationX"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AccelerometerEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(AccelerometerEvent_obj::UPDATE,"UPDATE");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AccelerometerEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(AccelerometerEvent_obj::UPDATE,"UPDATE");
};

Class AccelerometerEvent_obj::__mClass;

void AccelerometerEvent_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.events.AccelerometerEvent"), hx::TCanCast< AccelerometerEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AccelerometerEvent_obj::__boot()
{
}

} // end namespace flash
} // end namespace events
