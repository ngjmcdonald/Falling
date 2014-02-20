package ;
import flash.geom.Point;


/**
 * ...
 * @author nathan
 */
class PlatformManager
{
    private var platforms:List<Platform>;
    private var highestPlatform:Float;
	private var prevHighPlatform:Float;
    
    
    private static var _instance:PlatformManager;
    
    
    
    public static inline function instance():PlatformManager{
       if (_instance == null)
          return _instance = new PlatformManager();
      	else
          return _instance;
    }
    
	public function new() 
	{
        platforms = new List<Platform>();
		for(i in 0...100){
            platforms.add(new Platform());
        }
		
	}
    
    public function getPlatform(minPos:Point, maxPos:Point = null, isSetLocation:Bool = false):Platform {
		var pltfrm:Platform = platforms.pop();
        if (!isSetLocation) {
			//(Math.floor(Math.random() * (maxNum - minNum + 1)) + minNum);
			pltfrm.x = (Math.floor(Math.random() * (minPos.x - 0 + 1)) + 0);
			pltfrm.y = (Math.floor(Math.random() * ((minPos.y) - (minPos.y - 300) + 1)) + (minPos.y - 300));
			pltfrm.y *= -1;
			
			
		}else {
			pltfrm.x = minPos.x;
			pltfrm.y = minPos.y;
		}
		
		if (Math.abs(pltfrm.y) > prevHighPlatform ) {
			highestPlatform = pltfrm.y;
		}
		prevHighPlatform = highestPlatform;
		//trace(pltfrm.y + " " + pltfrm.x);
        
        return pltfrm;
    }
    
    public function returnPlatform(platfrm:Platform){
        platforms.add(platfrm);
    }
	
	public function getPlatforms():List<Platform> {
		return platforms;
	}
	
    
	
}