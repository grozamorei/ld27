package flx.core;
import org.flixel.FlxG;
import flash.geom.Point;
import flx.state.level.LevelBase;
import org.flixel.FlxSprite;
class Lever extends FlxSprite {

    public static var TOTAL_LEVERS:Int;
    public static var LEVERS_PULLED:Int;

    public function new(x:Float, y:Float, level:LevelBase) {
        super(x, y);

        LEVERS_PULLED = 0;

        this.loadGraphic('assets/button1_tilesheet.png', false, false, 64, 64);
        frame = 0;

        lvl = level;
        myPt = new Point(this.x + 32, this.y + 32);
    }

    private var lvl:LevelBase;
    private var myPt:Point;

    override public function update():Void {
        super.update();

        if (frame == 1) return;

        var _heroFl:Point = new Point(lvl.player.x + lvl.player.width / 2, lvl.player.y + lvl.player.height / 2);
        var distance:Float = Point.distance(_heroFl, myPt);

        if (distance < 32) {
            if (frame == 0) {
                frame = 1;
                FlxG.camera.shake(0.01, 0.7);
                LEVERS_PULLED++;
                if (1 == LEVERS_PULLED) {
                    lvl.hud.notify('Path to boss was opened..');
                    lvl.openBoss();
                } else {
                    lvl.hud.notify('Only ' + (TOTAL_LEVERS - LEVERS_PULLED) + ' more to go...');
                }
            }
        }
    }
}