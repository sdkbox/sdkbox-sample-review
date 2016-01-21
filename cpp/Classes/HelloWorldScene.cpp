
#include "HelloWorldScene.h"
#include "PluginReview/PluginReview.h"

USING_NS_CC;

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

    CCLOG("Sample Startup");

    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);

    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));

    // add test menu
    createTestMenu();

    return true;
}

void HelloWorld::createTestMenu()
{
    MenuItemFont::setFontName("sans");
    Size size = Director::getInstance()->getWinSize();
    
    // init plugin
    auto menu = Menu::create(MenuItemFont::create("show review", CC_CALLBACK_1(HelloWorld::onShowReview, this)),
                             NULL);
    
    menu->alignItemsVerticallyWithPadding(5);
    menu->setPosition(Vec2(size.width/2, size.height/2));
    addChild(menu);
}

void HelloWorld::onShowReview(cocos2d::Ref* sender)
{
    sdkbox::PluginReview::show(true /* force */);
    CCLOG("sdkbox::PluginReview::show()");
}

void HelloWorld::onDisplayAlert()
{
    CCLOG("onDisplayAlert");
}

void HelloWorld::onDeclineToRate()
{
    CCLOG("onDeclineToRate");
}

void HelloWorld::onRate()
{
    CCLOG("onRate");
}

void HelloWorld::onRemindLater()
{
    CCLOG("onRemindLater");
}
