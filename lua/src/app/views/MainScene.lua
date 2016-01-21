
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
    cc.MenuItemFont:setFontName("sans")
    local size = cc.Director:getInstance():getWinSize()

    -- init plugin
    sdkbox.PluginReview:init()
    sdkbox.PluginReview:setListener(function(args)
        local event = args.event
        if "onDisplayAlert" == event then
            print("onDisplayAlert")
        elseif "onDeclineToRate" == event then
            print("onDeclineToRate")
        elseif "onRate" == event then
            print("onRate")
        elseif "onRemindLater" == event then
            print("onRemindLater")
        end
    end)

    local menu = cc.Menu:create(
        cc.MenuItemFont:create("show review"):onClicked(function()
            sdkbox.PluginReview:show(true --[[ force ]])
            print("sdkbox.PluginReview:show()")
        end)
    )

    menu:alignItemsVerticallyWithPadding(5)
    menu:setPosition(size.width/2, size.height/2)
    self:addChild(menu)
end

return MainScene
