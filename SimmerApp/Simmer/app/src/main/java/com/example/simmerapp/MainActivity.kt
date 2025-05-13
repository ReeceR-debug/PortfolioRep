package com.example.simmerapp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.PersistableBundle
import android.view.Menu
import android.view.MenuInflater
import android.view.MenuItem
import android.widget.Button
import android.widget.ImageButton
import android.widget.Toast
import androidx.appcompat.widget.Toolbar

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        //buttons to take you to individual recipe pages
        val mainTXTbeefBroc = findViewById<Button>(R.id.btnBeefTXT)
        val mainIMGbeefBroc = findViewById<ImageButton>(R.id.btnBeef)


        mainTXTbeefBroc.setOnClickListener {

            val intent = Intent(this, BeefBroc::class.java)
            startActivity(intent)
        }
        mainIMGbeefBroc.setOnClickListener {
            val intent = Intent(this, BeefBroc::class.java)
            startActivity(intent)

        }
        val mainTXTsmash = findViewById<Button>(R.id.btnSmashTXT)
        val mainIMGsmash = findViewById<ImageButton>(R.id.btnSmash)


        mainTXTsmash.setOnClickListener {

            val intent = Intent(this, SmashPatty::class.java)
            startActivity(intent)
        }
        mainIMGsmash.setOnClickListener {
            val intent = Intent(this, SmashPatty::class.java)
            startActivity(intent)

        }
        val mainTXTking = findViewById<Button>(R.id.btnChickenTXT)
        val mainIMGking = findViewById<ImageButton>(R.id.btnChicken)


        mainTXTking.setOnClickListener {

            val intent = Intent(this, ChickenKing::class.java)
            startActivity(intent)
        }
        mainIMGking.setOnClickListener {
            val intent = Intent(this, ChickenKing::class.java)
            startActivity(intent)

        }
        val mainTXTgoulash = findViewById<Button>(R.id.btnGoulashTXT)
        val mainIMGgoulash = findViewById<ImageButton>(R.id.BtnGoulash)


        mainTXTgoulash.setOnClickListener {

            val intent = Intent(this, Goulash::class.java)
            startActivity(intent)
        }
        mainIMGgoulash.setOnClickListener {
            val intent = Intent(this, Goulash::class.java)
            startActivity(intent)

        }
        val mainTXTlasagna = findViewById<Button>(R.id.btnLasagnaTXT)
        val mainIMGlasagna = findViewById<ImageButton>(R.id.btnLasagna)


        mainTXTlasagna.setOnClickListener {

            val intent = Intent(this, Lasagna::class.java)
            startActivity(intent)
        }
        mainIMGlasagna.setOnClickListener {
            val intent = Intent(this, Lasagna::class.java)
            startActivity(intent)

        }
        val mainTXTaddNew = findViewById<Button>(R.id.btnAddNewTXT)
        val mainIMGaddNew = findViewById<ImageButton>(R.id.btnAddNew)


        mainTXTaddNew.setOnClickListener {

            val intent = Intent(this, AddNew::class.java)
            startActivity(intent)
        }
        mainIMGaddNew.setOnClickListener {
            val intent = Intent(this, AddNew::class.java)
            startActivity(intent)

        }

    }



    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu, menu)
        return true
    }
    //Code for the drop down menu at the top of the screen
    override fun onOptionsItemSelected(item: MenuItem): Boolean {

        when(item!!.itemId){
        R.id.home -> {val intent = Intent(this, MainActivity::class.java)
            startActivity(intent)}
        R.id.about_contacts -> {val intent = Intent(this, AboutUs::class.java)
            startActivity(intent)}
        R.id.favorites -> Toast.makeText(this, "Currently Not Available", Toast.LENGTH_SHORT).show()
        }
        return super.onOptionsItemSelected(item)
    }
}