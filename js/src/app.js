
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        // var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
        //     cc.log("QUIT");
        // });
        // var menu = new cc.Menu(quit);
        // var size = quit.getContentSize();
        // menu.x = winsize.width - size.width / 2 - 16;
        // menu.y = size.height / 2 + 16;
        // this.addChild(menu);

        return true;
    },

    createTestMenu:function() {
        var menu = new cc.Menu();

        var item1 = new cc.MenuItemLabel(new cc.LabelTTF("banner", "sans", 28), function() {
            sdkbox.PluginPhunwareAds.show("banner");
        });
        menu.addChild(item1);

        var item2 = new cc.MenuItemLabel(new cc.LabelTTF("interstitial", "sans", 28), function() {
            sdkbox.PluginPhunwareAds.show("interstitial");
        });
        menu.addChild(item2);

        var item3 = new cc.MenuItemLabel(new cc.LabelTTF("reward", "sans", 28), function() {
            sdkbox.PluginPhunwareAds.show("reward");
        });
        menu.addChild(item3);

        var item4 = new cc.MenuItemLabel(new cc.LabelTTF("page", "sans", 28), function() {
            sdkbox.PluginPhunwareAds.show("page");
        });
        menu.addChild(item4);

        var item5 = new cc.MenuItemLabel(new cc.LabelTTF("video", "sans", 28), function() {
            sdkbox.PluginPhunwareAds.show("video");
        });
        menu.addChild(item5);

        var winsize = cc.winSize;
        menu.x = winsize.width / 2;
        menu.y = winsize.height / 2;
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu);

        //
        sdkbox.PluginPhunwareAds.setUserID("js123");
        sdkbox.PluginPhunwareAds.init();
        sdkbox.PluginPhunwareAds.setListener({

            adLoaded : function(name) { cc.log("adLoaded " + name) },
            adFailed : function(name, errorCode, msg) { cc.log("adFailed " + name + " " + msg) },
            adWillPresent : function(name) { cc.log("adWillPresent " + name) },
            adDidPresent : function(name) { cc.log("adDidPresent " + name) },
            adWillDissmiss : function(name) { cc.log("adWillDissmiss " + name) },
            adDidDismiss : function(name) { cc.log("adDidDismiss " + name) },
            willLeaveApp : function(name) { cc.log("willLeaveApp " + name)},
            reward : function(name, amount, currency) { cc.log("reward " + name) },

        });
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

