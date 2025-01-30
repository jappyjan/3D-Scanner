require("keys")

exitScript = false
event.keypress = function(key)
    if key == "HALFSHUTTER" then
        print("HALFSHUTTER")
        lens.focus(1)
    end

    if key == "UNPRESS_HALFSHUTTER" then
        print("UNPRESS_HALFSHUTTER")
    end

    if key == "FULLSHUTTER" then
        print("FULLSHUTTER")
        -- camera.wait()
        -- camera.shoot()
        -- camera.wait()
    end

    if key == "UNPRESS_FULLSHUTTER" then
        print("UNPRESS_FULLSHUTTER")
    end

    if key == "TRASH" then
        print("TRASH")
        exitScript = true
    end
end

function main()
    keys:start()
    menu.close()
    menu.block(true)
    console.show()
    print("3D Scanner")

    while not exitScript do
        key.wait()
    end

    menu.block(false)
    keys:stop()
    console.hide()
end

scanner_menu = menu.new
{
    name    = "3D Scanner",
    help    = "Helper Script for 3D Scanning",
    select = function(this) 
        task.create(function() main() end)
    end
}