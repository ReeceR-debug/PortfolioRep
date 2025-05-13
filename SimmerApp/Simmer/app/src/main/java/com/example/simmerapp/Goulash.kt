package com.example.simmerapp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.widget.ImageButton
import android.widget.Toast

class Goulash : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_goulash)

        val buttonBackToMainFromBeef = findViewById<ImageButton>(R.id.btnBackarrowGoulash)

        // Set the OnClickListener to go back to MainActivity when clicked
        buttonBackToMainFromBeef.setOnClickListener {
            // Create an intent to go back to MainActivity
            val intent = Intent(this, MainActivity::class.java)
            startActivity(intent)
        }
    }
    // This is a test comment
    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu, menu)
        return true
    }

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