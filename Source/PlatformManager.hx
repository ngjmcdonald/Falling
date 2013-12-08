package ;


/**
 * ...
 * @author nathan
 */
class PlatformManager
{
    private var platforms:List<Platform>;
    
    
    
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
		for(i in 0...20){
            platforms.add(new Platform());
        }
		
	}
    
    public function getPlatform(sHeight:Float,sWidth:Float):Platform{
        var pltfrm:Platform = platforms.pop();
        pltfrm.x = (Math.random() * sWidth);
        pltfrm.y = (Math.random() * sHeight);
        return pltfrm;
    }
    
    public function returnPlatform(platfrm:Platform){
        platforms.add(platfrm);
    }
    
	
}