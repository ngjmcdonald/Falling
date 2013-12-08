package;


import flash.display.Sprite;
import flash.display.Bitmap;
import flash.events.KeyboardEvent;
import flash.geom.Point;
import flash.ui.Keyboard;
import flash.events.Event;
import openfl.Assets;
import flash.events.AccelerometerEvent;
import flash.sensors.Accelerometer;
import flash.text.TextField;
import flash.text.TextFormat;
import flash.geom.Rectangle;





class Main extends Sprite {
	
	private var characterContainer:Sprite;
	private var character:MainCharacter;
	private var moveLeft:Bool;
	private var moveRight:Bool;
	private var textField:TextField;
	private var acc:Accelerometer;
    private var platformsOnStage:List<Platform>;
    private var jumping:Bool; 
	
	
	private var characterSpeed:Point;
	private var characterAccel:Point;
	private var acceleration:Float;
	
	public function new () {
		
		super ();
		platformsOnStage = new List<Platform>();
        
        
		textField = new TextField();
		acc = new Accelerometer();
        characterSpeed = new Point();
		
		characterSpeed.x = 25;
		characterSpeed.y = 2;
        
		acceleration = 1;
		
		textField.x = 300;
		textField.y = 300;
		textField.text = "Hello";
		textField.width = 200;
		
		addChild(textField);
		
		characterContainer = new Sprite();
		character = new MainCharacter();
		characterContainer.addChild(character);
        character.x = 300;
        character.y = 300;
        
        for(i in 0...10){
            
            var pltfrm:Platform = PlatformManager.instance().getPlatform(stage.stageHeight,stage.stageWidth);
            platformsOnStage.add(pltfrm);
            characterContainer.addChild(pltfrm);       
        }
        
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
                    characterSpeed.y = -25;    
                }
                
            }
        }
        //update physics
        // terminal velocity checked
        if(characterSpeed.y < 30)characterSpeed.y += acceleration;
        
        
        //apply physics
        character.y += characterSpeed.y;
        textField.text = Std.string(characterSpeed);
        
		if ((character.y + character.height > stage.stageHeight)) {
            characterSpeed.y = 0;
            character.y =  stage.stageHeight - character.height;	
		}
        
		
		if (moveLeft){
            character.x -= 5;
            character.y -=5;
        }
		if(moveRight){
            character.y +=5;
            character.x += 5;
        }
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