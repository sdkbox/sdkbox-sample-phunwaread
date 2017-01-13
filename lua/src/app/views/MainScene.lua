
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    local menu = cc.Menu:create()

    local label1 = cc.Label:createWithSystemFont("show banner", "sans", 28)
    local item1 = cc.MenuItemLabel:create(label1)
    item1:onClicked(function()
        sdkbox.PluginPhunwareAds:show("banner")
    end)
    menu:addChild(item1)

    local label2 = cc.Label:createWithSystemFont("show interstitial", "sans", 28)
    local item2 = cc.MenuItemLabel:create(label2)
    item2:onClicked(function()
        sdkbox.PluginPhunwareAds:show("banner")
    end)
    menu:addChild(item2)

    local label3 = cc.Label:createWithSystemFont("show reward", "sans", 28)
    local item3 = cc.MenuItemLabel:create(label3)
    item3:onClicked(function()
        sdkbox.PluginPhunwareAds:show("banner")
    end)
    menu:addChild(item3)

    local label4 = cc.Label:createWithSystemFont("show page", "sans", 28)
    local item4 = cc.MenuItemLabel:create(label4)
    item3:onClicked(function()
        sdkbox.PluginPhunwareAds:show("banner")
    end)
    menu:addChild(item4)

    local label5 = cc.Label:createWithSystemFont("show video", "sans", 28)
    local item5 = cc.MenuItemLabel:create(label5)
    item3:onClicked(function()
        sdkbox.PluginPhunwareAds:show("banner")
    end)
    menu:addChild(item5)

    menu:alignItemsVerticallyWithPadding(24)
    self:addChild(menu)

    --
    sdkbox.PluginPhunwareAds:setUserID("lua123")
    sdkbox.PluginPhunwareAds:init()
    sdkbox.PluginPhunwareAds:setListener(function ( args )
        dump(args)
    end)
end

return MainScene
