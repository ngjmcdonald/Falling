package ;
import flash.display.Sprite;
import flash.display.Bitmap;
import openfl.Assets;


/**
 * ...
 * @author nathan
 */
class MainCharacter extends Sprite
{
    public var myGraphic:Bitmap;
	
	public function new() 
	{
		super();
		
		var bitmap:Bitmap = new Bitmap(Assets.getBitmapData("assets/character.png"));
        myGraphic = bitmap;
		
        
		addChild(bitmap);
        this.width = bitmap.width;
		this.height = bitmap.height;
		
		
	}
	
}