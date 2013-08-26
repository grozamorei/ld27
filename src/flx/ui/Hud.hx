package flx.ui;
import haxe.Timer;
import org.flixel.plugin.photonstorm.FlxBar;
import flx.state.level.LevelBase;
import motion.Actuate;
import org.flixel.FlxText;
import flx.ui.EnemyLifeBar;
import haxe.ds.ObjectMap;
import flx.core.Enemy;
import haxe.ds.IntMap;
import flx.core.Facade;
import flx.core.Player;
import org.flixel.FlxG;
import org.flixel.util.FlxPoint;
import org.flixel.FlxGroup;
import org.flixel.FlxSprite;

class Hud extends FlxGroup {

    public function new(level:LevelBase) {
        super();

        model = Facade.I;
        this.level = level;

        notifyText = new FlxText(216, 150, 400, '', 15);
        notifyText.setFormat(null, 15, 0xFFFFFF, 'center', 0x000000, true);
        add(notifyText);

        lastNotify = 0;
    }

    private var level:LevelBase;
    private var player:Player;
    private var model:Facade;

    private var notifyText:FlxText;

    private var lastNotify:Float;

    public function notify(text:String):Void {
        lastNotify = Timer.stamp();
        notifyText.text = text;
        notifyText.visible = true;
    }

    public function injectPlayer(player:Player):Void {
        this.player = player;

        var playerHp:FlxBar = new FlxBar(70, 26, FlxBar.FILL_LEFT_TO_RIGHT, 256, 32, player, 'hp', 0, 200, false);
        playerHp.createImageBar(null, 'assets/an_hero_lifeBar.png', 0x000000);
        playerHp.currentValue = player.hp;
        playerHp.color = 0xf20000;
        playerHp.scrollFactor = new FlxPoint(0, 0);
        add(playerHp);

        var playerS:FlxBar = new FlxBar(70, 90, FlxBar.FILL_LEFT_TO_RIGHT, 256, 32, player, 'dmg', 0, 40, false);
        playerS.createImageBar(null, 'assets/an_hero_lifeBar.png', 0x000000);
        playerS.currentValue = player.dmg;
        playerS.scrollFactor = new FlxPoint(0, 0);
        add(playerS);

        var heart:FlxSprite = new FlxSprite(10, 10);
        heart.loadGraphic('assets/HUD_tilesheet.png', true, false, 64, 64, false);
        heart.addAnimation('normal', [0, 1, 2, 3], 4);
        heart.play('normal');
        heart.scrollFactor = new FlxPoint(0, 0);
        add(heart);

        var sword:FlxSprite = new FlxSprite(10, 74);
        sword.loadGraphic('assets/HUD_tilesheet.png', true, false, 64, 64, false);
        sword.addAnimation('normal', [4, 5, 6, 7], 4);
        sword.play('normal');
        sword.scrollFactor = new FlxPoint(0, 0);
        add(sword);
    }

    public function emitIncorporeal(fromEnemy:Enemy):Void {
        var launchPoint:FlxPoint = new FlxPoint(fromEnemy.myPt.x - FlxG.camera.x, fromEnemy.myPt.y - FlxG.camera.y);

        var text:FlxText = new FlxText(launchPoint.x - 60, launchPoint.y - 20, 120, 'Incorporeal', 12);
        text.setFormat(null, 12, 0xCCCCCCCC, 'center', 0xCC000000, true);

        add(text);
        Actuate.tween(text, 1.8, {y: text.y - 120, alpha: 0}).onComplete(function(hud:Hud, text:FlxText):Void {
            hud.remove(text, true);
        }, [this, text]);
    }

    override public function update():Void {
        super.update();

        if (Timer.stamp() - lastNotify > 2) {
             lastNotify = 0;
            notifyText.visible = false;
        } else {

        }
//        if (player.hp < 50) {
//
//        }
    }
}
