package;


import flash.display.Sprite;
import flash.display.Bitmap;
import flash.events.KeyboardEvent;
import flash.geom.Point;
import flash.net.URLLoader;
import flash.net.URLRequest;
import flash.ui.Keyboard;
import flash.events.Event;
import openfl.Assets;
import flash.events.AccelerometerEvent;
import flash.sensors.Accelerometer;
import flash.text.TextField;
import flash.text.TextFormat;
import flash.geom.Rectangle;
import flash.media.Sound;
import flash.utils.Timer;
import flash.xml.XML;





class Main extends Sprite {
	
	private var characterContainer:Sprite;
	private var character:MainCharacter;
	private var moveLeft:Bool;
	private var moveRight:Bool;
	private var textField:TextField;
	private var acc:Accelerometer;
    private var platformsOnStage:List<Platform>;
    private var jumping:Bool; 
    private var distance:Float = 0;
	private var generateTilesPoint:Float = 0;
    private var prevDistance:Float = 0;
    private var cameraMove:Bool = false;
	private var jumpSound:Sound;
	
	private var characterSpeed:Point;
	private var characterAccel:Point;
	private var acceleration:Float;
	
	public function new () {
		
		super ();
		jumpSound = Assets.getSound("assets/Jump.wav");
		var url:URLRequest = new URLRequest("assets/note.txt");
		var urlLoader:URLLoader = new URLLoader();
		urlLoader.
		//Xml.parse();
		
		
		platformsOnStage = new List<Platform>();
        
        
		textField = new TextField();
		acc = new Accelerometer();
        characterSpeed = new Point();
		
		characterSpeed.x = 30;
		characterSpeed.y = 0.5;
        
		acceleration = 0.1;
		
		textField.x = 50;
		textField.y = 50;
		textField.width = 200;
		
		addChild(textField);
		
		characterContainer = new Sprite();
		character = new MainCharacter();
		characterContainer.addChild(character);
        character.x = 300;
        character.y = 300;
        
        
        for(i in 0...3){
            //var hght:Float = stage.stageHeight;
            //if(i > 10) hght*=-6;
			var pltfrm:Platform = null;
			if (i == 0) {
				var pos:Point = new Point(character.x,character.y +character.height);
				pltfrm = PlatformManager.instance().getPlatform(pos, true);
			}else if (i == 1) {
				var pos:Point = new Point(350,200);
				pltfrm = PlatformManager.instance().getPlatform(pos,true);
			}else if (i == 2) {
				var pos:Point = new Point(350,-100);
				pltfrm = PlatformManager.instance().getPlatform(pos,true);
			}
			platformsOnStage.add(pltfrm);
			characterContainer.addChild(pltfrm);       
        }
		
            
        /*var pltfrm:Platform = PlatformManager.instance().getPlatform(stage.stageHeight,stage.stageWidth);
        pltfrm.x = ;
        pltfrm.y = ;
        platformsOnStage.add(pltfrm);
		characterContainer.addChild(pltfrm);*/
        
		addChild(characterContainer);
        
		stage.addEventListener(KeyboardEvent.KEY_DOWN, onKeyDown);
		stage.addEventListener(KeyboardEvent.KEY_UP, OnKeyUp);
		stage.addEventListener(Event.ENTER_FRAME, OnEnterFrame);
		
		acc.addEventListener(AccelerometerEvent.UPDATE, OnAcceleromterChange);
		
	}
	private function OnKeyUp(e:KeyboardEvent) {
        
		moveLeft = false;
		moveRight = false;
	}
    
	private function onKeyDown(e:KeyboardEvent) {
		
		switch(e.keyCode) {
			case Keyboard.LEFT:
				moveLeft = true;
			case Keyboard.RIGHT:
				moveRight = true;
		}
        
	}
	
	private function OnEnterFrame(e:Event) {
        
        // trace(distance);
        
		//trace(stage.stageHeight + " " + character.y+character.height );
        var currentHeight:Float = character.y;
        if(currentHeight < 0){
            currentHeight = (currentHeight *-1) + stage.stageHeight; 
        }else{
            currentHeight = stage.stageHeight - currentHeight;
        }
        if(prevDistance < currentHeight){
            distance = currentHeight;
			//trace(distance % 300 + " " + distance * .03);
			generateTilesPoint += (distance - prevDistance);
			//trace(generateTilesPoint + " " + stage.stageHeight);
			if (generateTilesPoint > stage.stageHeight/2) {
				generateTilesPoint = 0;
				// remove platforms from bottom
				if (PlatformManager.instance().getPlatforms().length < 10) {
					
					for (p in platformsOnStage) {
						
						if (Math.abs(p.y - character.y) >  600) {
							platformsOnStage.remove(p);
							characterContainer.removeChild(p);
							PlatformManager.instance().returnPlatform(p);
							
						}
					}
				}// add new platforms above
				var pltfrm:Platform = null;
				for (i in 0...5) {
					var newGenPoint:Float = (distance - 100);
					var pos1:Point = new Point(stage.stageWidth,newGenPoint);
					
					pltfrm = PlatformManager.instance().getPlatform(pos1);
					
					platformsOnStage.add(pltfrm);
					characterContainer.addChild(pltfrm); 
				}
			}
        }
            
        
            
        
        // position character on inverse side of screen when the one side is entered
		if (character.x > stage.stageWidth) {
			character.x = (0 - character.width);
		}
		if (character.x  < (0 - character.width) ) {
			character.x = stage.stageWidth;
		}
        
        // add jump
        for(p in platformsOnStage){
            if(collidingWithPlatform(character,p)){
                if(characterSpeed.y > 0 && character.y + character.height < p.y + p.height){
                    characterSpeed.y = -10;
                    jumpSound.play();
                }
            }
        }
        //update physics
        // terminal velocity checked
        if(characterSpeed.y < 30)characterSpeed.y += acceleration;
        
        
        //apply physics
        character.y += characterSpeed.y;
        
        
        if(prevDistance != 0){
            characterContainer.y += (distance - prevDistance);    
        }
  
        textField.text = Std.string(distance);
        
		if ((character.y + character.height > stage.stageHeight)) {
            characterSpeed.y = 0;
            character.y =  stage.stageHeight - character.height;	
		}
        
		
		if (moveLeft){
            character.x -= 5;
        }
		if(moveRight){
            character.x += 5;
        }
        prevDistance = distance;
	}
	
	private function OnAcceleromterChange(e:AccelerometerEvent) {
		
		
		var speed:Float = (characterSpeed.x * e.accelerationX);
		
		if (e.accelerationX < -0.1 || e.accelerationX > 0.1) {
			character.x -= speed;
		}
	}
    
    private function collidingWithPlatform(obj1:MainCharacter,obj2:Platform):Bool{
        var rect1:Rectangle = new Rectangle(obj1.x,obj1.y,obj1.width,obj1.height);
        var rect2:Rectangle = new Rectangle(obj2.x,obj2.y,obj2.width,obj2.height);
        
        return rect1.intersects(rect2); 
    }  
    
    
    
	
}