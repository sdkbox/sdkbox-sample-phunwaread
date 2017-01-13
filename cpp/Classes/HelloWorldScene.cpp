#include "HelloWorldScene.h"
#include "PluginPhunwareAds/PluginPhunwareAds.h"


USING_NS_CC;

using namespace sdkbox;
#include <vector>
#include <string>
using namespace std;

std::vector<std::string> msgbuf;
static void showMsg(const std::string& msg) {
    static int msgIndex = 0;
    //
    Label *label = dynamic_cast<Label*>(Director::getInstance()->getNotificationNode());
    if (label == nullptr) {
        auto size = Director::getInstance()->getWinSize();
        label = Label::createWithSystemFont("test", "arial", 16);
        label->setAnchorPoint(ccp(0,0));
        label->setTextColor(Color4B(0, 255, 0, 255));
        label->setPosition(10, size.height*0.1);
        Director::getInstance()->setNotificationNode(label);
    }

    stringstream buf;
    buf << msgIndex++ << " " << msg << "\n";
    msgbuf.push_back(buf.str());
    if (msgbuf.size() > 10) {
        msgbuf.erase(msgbuf.cbegin());
    }


    std::string text = "";
    for (int i = 0; i < msgbuf.size(); i++) {
        text = text + msgbuf[i];
    }

    label->setString(text);
}


class CustomListener : public sdkbox::PhunwareAdsListener {
public:

    virtual void adLoaded(const std::string& name) {
        CCLOG("%s: name=%s", __FUNCTION__, name.c_str());
        showMsg(StringUtils::format("%s: name=%s", __FUNCTION__, name.c_str()));
    }
    virtual void adFailed(const std::string& name, const std::string& msg) {
        CCLOG("%s: name=%s msg=%s", __FUNCTION__, name.c_str(), msg.c_str());
        showMsg(StringUtils::format("%s: name=%s error msg=%s", __FUNCTION__, name.c_str(), msg.c_str()));
    }
    virtual void adWillPresent(const std::string& name) {
        CCLOG("%s: name=%s", __FUNCTION__, name.c_str());
        showMsg(StringUtils::format("%s: name=%s", __FUNCTION__, name.c_str()));
    }
    virtual void adDidPresent(const std::string& name) {
        CCLOG("%s: name=%s", __FUNCTION__, name.c_str());
        showMsg(StringUtils::format("%s: name=%s", __FUNCTION__, name.c_str()));
    }
    virtual void adWillDissmiss(const std::string& name) {
        CCLOG("%s: name=%s", __FUNCTION__, name.c_str());
        showMsg(StringUtils::format("%s: name=%s", __FUNCTION__, name.c_str()));
    }
    virtual void adDidDismiss(const std::string& name) {
        CCLOG("%s: name=%s", __FUNCTION__, name.c_str());
        showMsg(StringUtils::format("%s: name=%s", __FUNCTION__, name.c_str()));
    }
    virtual void willLeaveApp(const std::string& name) {
        CCLOG("%s: name=%s", __FUNCTION__, name.c_str());
        showMsg(StringUtils::format("%s: name=%s", __FUNCTION__, name.c_str()));
    }
    virtual void reward(const std::string& name, float amount, const std::string& currency) {
        CCLOG("%s: name=%s", __FUNCTION__, name.c_str());
        showMsg(StringUtils::format("%s: name=%s, amount=%0.1f, currency=%s", __FUNCTION__, name.c_str(), amount, currency.c_str()));
    }
};


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    sdkbox::PluginPhunwareAds::setListener(new CustomListener());
    sdkbox::PluginPhunwareAds::setUserID("1234");
    sdkbox::PluginPhunwareAds::init();

    // ui
    auto size = Director::getInstance()->getWinSize();
    CCMenuItemFont::setFontSize(48);
    CCMenuItemFont::setFontName("sans");
    CCMenuItemFont *item = CCMenuItemFont::create("show banner", [](Ref*) {
        sdkbox::PluginPhunwareAds::show("banner");
    });
    CCMenuItemFont *item2 = CCMenuItemFont::create("show interstitial", [](Ref*) {
        sdkbox::PluginPhunwareAds::show("interstitial");
    });
    CCMenuItemFont *item3 = CCMenuItemFont::create("show reward", [](Ref*) {
        sdkbox::PluginPhunwareAds::show("reward");
    });
    CCMenuItemFont *item4 = CCMenuItemFont::create("show page", [](Ref*) {
        sdkbox::PluginPhunwareAds::show("page");
    });
    CCMenuItemFont *item5 = CCMenuItemFont::create("show video", [](Ref*) {
        sdkbox::PluginPhunwareAds::show("video");
    });
    CCMenuItemFont *item1 = CCMenuItemFont::create("hide banner", [](Ref*) {
        sdkbox::PluginPhunwareAds::hide("banner");
    });
    CCMenuItemFont *item6 = CCMenuItemFont::create("getRemainingViews", [](Ref*) {
        std::string name = "reward";
        int remainingViews = sdkbox::PluginPhunwareAds::getRemainingViews(name);
        showMsg(StringUtils::format("name=%s, remainingViews=%d", name.c_str(), remainingViews));
    });
    CCMenu *menu = CCMenu::create(item, item1, item2, item3, item4, item5, item6, NULL);
    this->addChild(menu);
    menu->setAnchorPoint(Point(0, 0));
    menu->setPosition(size.width/2, size.height/2);
    menu->alignItemsVerticallyWithPadding(10);
    
    return true;
}

