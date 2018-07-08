package routers

import (
	"github.com/astaxie/beego"
	"gps/controllers"
)

func init() {
	beego.Router("/", &controllers.MainController{}, "get:Hello")
	beego.Router("/ajax_dict", &controllers.MainController{}, "get:GetRecord")
	beego.Router("/site_table", &controllers.MainController{}, "get:SiteTable")

}
