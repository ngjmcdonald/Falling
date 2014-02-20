package ;
import flash.display.Sprite;
import openfl.Assets;
import flash.display.Bitmap;
import flash.events.Event;

/**
 * ...
 * @author nathan
 */
class Platform extends Sprite
{
    public var myGraphic:Bitmap;
    
	public function new() 
	{
		super();
		var bitmap:Bitmap = new Bitmap(Assets.getBitmapData("assets/platform.png"));
        myGraphic = bitmap;
        
		addChild(bitmap);
		
		this.addEventListener(Event.ENTER_FRAME, OnEnterFrame);
	}
	private function OnEnterFrame(e:Event) {
		if (stage != null) {
			//trace();
			if (this.y > stage.height) {
				trace(" bye bye");
				PlatformManager.instance().returnPlatform(this);
			}
		}
		
	}
	
}