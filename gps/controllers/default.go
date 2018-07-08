package controllers

import (
	"fmt"
	"github.com/astaxie/beego"
	"gps/models"
)

type MainController struct {
	beego.Controller
}

type Status struct {
	ErrMsg string `json:"errMsg"`
}

func (c *MainController) GetRecord() {
	var resp models.Resp
	var errMsg Status
	var err error
	resp.Records, err = models.GetRecord()
	if err != nil {
		errMsg.ErrMsg = "DB_OPERATION_ERROR:" + err.Error()
		c.Data["json"] = errMsg
	} else {
		for i := range resp.Records {
			fmt.Println(resp.Records[i])
		}
		c.Data["json"] = resp
	}

	c.ServeJSON()
	c.StopRun()
}

func (c *MainController) Hello() {
	c.TplName = "hello.html"
}

func (c *MainController) SiteTable() {
	c.TplName = "site_table.html"
}
