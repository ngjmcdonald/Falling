package ;
import flash.display.Sprite;
import openfl.Assets;
import flash.display.Bitmap;

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
	}
	
}